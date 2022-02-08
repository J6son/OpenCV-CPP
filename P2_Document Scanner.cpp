#include<iostream> 
#include<opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp> 
#include <opencv2/highgui.hpp> 
using namespace cv;
using namespace std;

///////Document Scanner////////

Mat imgOG,imgThreshold,imgGray,imgBlur, imgCanny,imgDil,imgWarp,imgCrop;
vector<Point> initPoint,docPoint;

float w = 420, h = 596; //A4ֽ��С*2

Mat preProcessing(Mat img)
{
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 3);
    Canny(imgBlur, imgCanny, 25, 75);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(imgCanny, imgDil, kernel);

    return imgDil;
}

////����ͼ����ȡ��Ե ��ԭͼ�ϻ�����Ե ���������ε��ĸ���
vector<Point> getContours(Mat imgDilate)
{
    vector<vector<Point>> contours; //������Ϣ ��Ե��
    vector<Vec4i> hierarchy; //�㼶��ϵ ��һ��������š���һ��������š���������š����������

    findContours(imgDilate, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    
    //ȥ������ ��������������
    vector<vector<Point>> conPoly(contours.size());//�˵� ����4�� Բ�ܶ��
    vector<Rect> boundRect(contours.size()); //���ο������
    string objectType; //��������

    vector<Point> biggest;
    double maxArea = 0;
    for (int i = 0; i < contours.size(); i++)
    {
        //�������
        double area = contourArea(contours[i]);
        cout << "������� "<<area << endl;
        //ȥ������
        if (area > 1000)
        {
            //�������������ܳ������ߵĳ��� true��ʾ���߱պ�
            double peri = arcLength(contours[i], true);
            
            //��һ�������⻬�������߻� ���ٶ˵��� �浽conPoly��
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

//����x+y��������С ������� x-y��������� ������С
vector<Point> reorder(vector<Point>point)
{
    vector<Point> newPoint;
    vector<int> sumPoint, subPoint;

    for (int i = 0; i < 4; i++)
    {
        sumPoint.push_back(point[i].x + point[i].y);
        subPoint.push_back(point[i].x - point[i].y);
    }
    //������������Сֵ�����ֵ��ָ�� ȡֵ��* ȡ�±�Ҫ���׵�ַ���
    newPoint.push_back(point[min_element(sumPoint.begin(), sumPoint.end())-sumPoint.begin()]);//���� 0
    newPoint.push_back(point[max_element(subPoint.begin(), subPoint.end()) - subPoint.begin()]);//���� 1
    newPoint.push_back(point[min_element(subPoint.begin(), subPoint.end()) - subPoint.begin()]);//���� 2
    newPoint.push_back(point[max_element(sumPoint.begin(), sumPoint.end()) - sumPoint.begin()]);//���� 3

    return newPoint;
}

Mat getWarp(Mat img,vector<Point>point,float w,float h)
{
    Point2f src[4] = { point[0],point[1],point[2],point[3] };
    Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

    //����������������ͼ��͸�ӱ任�ľ���
    //������ͶӰ��һ���µ���ƽ�� Ҳ����ͶӰӳ��
    //��б��ͼ ��Ϊ ����ͼ
    Mat matrix = getPerspectiveTransform(src, dst);
    Mat imgWarp;
    warpPerspective(img, imgWarp, matrix, Point(w, h));

    return imgWarp;
}

void main()
{
    string path = "Resources/paper.jpg";
    imgOG = imread(path);
    //resize(imgOG, imgOG, Size(), 0.5, 0.5);//����ͼƬģ��

    //preprocessing  
    imgThreshold = preProcessing(imgOG);

    //get contours -biggest rect
    initPoint = getContours(imgThreshold);

    //ԭͼ�ϻ��������ε��ĸ�����
    //drawPoint(initPoint, Scalar(0, 0, 255));
    //�������� 0-���� 1-���� 2-���� 3-���� ��͸�ӱ任����˳��һ��
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