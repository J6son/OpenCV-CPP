#include<iostream> 
#include<opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp> 
#include <opencv2/highgui.hpp> 
using namespace cv;
using namespace std;

///////Document Scanner////////

Mat imgOG,imgThreshold,imgGray,imgBlur, imgCanny,imgDil,imgWarp,imgCrop;
vector<Point> initPoint,docPoint;

float w = 420, h = 596; //A4纸大小*2

Mat preProcessing(Mat img)
{
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 3);
    Canny(imgBlur, imgCanny, 25, 75);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(imgCanny, imgDil, kernel);

    return imgDil;
}

////膨胀图上提取边缘 在原图上画出边缘 返回最大矩形的四个点
vector<Point> getContours(Mat imgDilate)
{
    vector<vector<Point>> contours; //轮廓信息 边缘点
    vector<Vec4i> hierarchy; //层级关系 上一个轮廓序号、下一个轮廓序号、子轮廓序号、父轮廓序号

    findContours(imgDilate, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    
    //去除噪声 不画噪声的轮廓
    vector<vector<Point>> conPoly(contours.size());//端点 矩形4个 圆很多个
    vector<Rect> boundRect(contours.size()); //矩形框出轮廓
    string objectType; //轮廓名称

    vector<Point> biggest;
    double maxArea = 0;
    for (int i = 0; i < contours.size(); i++)
    {
        //轮廓面积
        double area = contourArea(contours[i]);
        cout << "轮廓面积 "<<area << endl;
        //去除噪声
        if (area > 1000)
        {
            //计算封闭轮廓的周长或曲线的长度 true表示曲线闭合
            double peri = arcLength(contours[i], true);
            
            //把一个连续光滑曲线折线化 减少端点数 存到conPoly中
            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
            
            if (area > maxArea && conPoly[i].size() == 4)
            {
                biggest = { conPoly[i][0],conPoly[i][1], conPoly[i][2], conPoly[i][3] };
                maxArea = area;
                drawContours(imgOG, conPoly, i, Scalar(255, 0, 255), 2);
            }
            //rectangle(imgOG, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0),2);
        }
    }
    return biggest;
}

void drawPoint(vector<Point>point,Scalar color)
{
    for (int i = 0; i < point.size(); i++)
    {
        circle(imgOG, point[i], 10, color, FILLED);
        putText(imgOG, to_string(i), point[i], FONT_HERSHEY_PLAIN, 4, color, 4);
    }
}

//坐标x+y：左上最小 右下最大 x-y：右上最大 左下最小
vector<Point> reorder(vector<Point>point)
{
    vector<Point> newPoint;
    vector<int> sumPoint, subPoint;

    for (int i = 0; i < 4; i++)
    {
        sumPoint.push_back(point[i].x + point[i].y);
        subPoint.push_back(point[i].x - point[i].y);
    }
    //返回容器中最小值和最大值的指针 取值用* 取下标要与首地址相减
    newPoint.push_back(point[min_element(sumPoint.begin(), sumPoint.end())-sumPoint.begin()]);//左上 0
    newPoint.push_back(point[max_element(subPoint.begin(), subPoint.end()) - subPoint.begin()]);//右上 1
    newPoint.push_back(point[min_element(subPoint.begin(), subPoint.end()) - subPoint.begin()]);//左下 2
    newPoint.push_back(point[max_element(sumPoint.begin(), sumPoint.end()) - sumPoint.begin()]);//右下 3

    return newPoint;
}

Mat getWarp(Mat img,vector<Point>point,float w,float h)
{
    Point2f src[4] = { point[0],point[1],point[2],point[3] };
    Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

    //根据输入和输出点获得图像透视变换的矩阵
    //将成像投影到一个新的视平面 也称作投影映射
    //倾斜的图 变为 俯视图
    Mat matrix = getPerspectiveTransform(src, dst);
    Mat imgWarp;
    warpPerspective(img, imgWarp, matrix, Point(w, h));

    return imgWarp;
}

void main()
{
    string path = "Resources/paper.jpg";
    imgOG = imread(path);
    //resize(imgOG, imgOG, Size(), 0.5, 0.5);//会让图片模糊

    //preprocessing  
    imgThreshold = preProcessing(imgOG);

    //get contours -biggest rect
    initPoint = getContours(imgThreshold);

    //原图上画出最大矩形的四个顶点
    //drawPoint(initPoint, Scalar(0, 0, 255));
    //重新排序 0-左上 1-右上 2-左下 3-右下 与透视变换矩阵顺序一致
    docPoint = reorder(initPoint);
    drawPoint(docPoint, Scalar(0, 255, 0));

    //warp
    imgWarp = getWarp(imgOG, docPoint, w, h);

    //Crop
    int cropVal = 10;
    Rect roi(cropVal, cropVal, w - 2 * cropVal, h - 2 * cropVal);
    imgCrop = imgWarp(roi);

    imshow("imgOG", imgOG);
    imshow("image Dilation", imgDil);
    imshow("image Warp", imgWarp);
    imshow("image Crop", imgCrop);

    waitKey(0);
}