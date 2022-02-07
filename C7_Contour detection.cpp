//#include<iostream> 
//#include <opencv2/imgproc.hpp> 
//#include <opencv2/highgui.hpp> 
//
//using namespace cv;
//using namespace std;
//
//////////////Contour detection///////////////////
//
//Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;
//
//////膨胀图上提取边缘 在原图上画出边缘
//void getContours(Mat imgDilate,Mat imgOG)
//{
//    vector<vector<Point>> contours; //轮廓信息 边缘点
//    vector<Vec4i> hierarchy; //层级关系 上一个轮廓序号、下一个轮廓序号、子轮廓序号、父轮廓序号
//
//    //mode 轮廓检索算法的模式 获取怎样的层级信息
//    //RETR_EXTERNAL模式是只找最外层的轮廓
//    //RETR_LIST模式是找到所有的轮廓，但是不提供层级关系
//    //RETR_CCOMP模式是找到所有轮廓，层级只有两层（外轮廓和洞，洞里面再有轮廓按照外轮廓算
//    //RETR_TREE模式是以树状梳理所有轮廓的关系
//
//    //method拟合方法
//    //CHAIN_APPROX_NONE是不做处理 
//    //CHAIN_APPROX_SIMPLE会将直线和对角线优化掉 横竖撇捺都压缩得只剩下顶点
//    //CHAIN_APPROX_TC89_L1和CHAIN_APPROX_TC89_KCOS采用了近似算法
//    
//    findContours(imgDilate, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
//    
//    //                        -1画出所有轮廓
//    //drawContours(imgOG, contours, -1, Scalar(255, 0, 255), 2);
//
//    //去除噪声 不画噪声的轮廓
//    vector<vector<Point>> conPoly(contours.size());//角点 矩形4个 圆很多个
//    vector<Rect> boundRect(contours.size()); //矩形框出轮廓
//    string objectType; //轮廓名称
//    for (int i = 0; i < contours.size(); i++)
//    {
//        //轮廓面积
//        double area = contourArea(contours[i]);
//        cout << "轮廓面积 "<<area << endl;
//        //去除噪声
//        if (area > 1000)
//        {
//            //计算封闭轮廓的周长或曲线的长度 true表示曲线闭合
//            float peri = arcLength(contours[i], true);
//            
//            //把一个连续光滑曲线折线化
//            //第三个参数 原始曲线与近似曲线之间的最大距离
//            //距离大于此阈值则舍弃，小于则保留，epsilon越小，折线的形状越“接近”曲线
//            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
//            
//            //此轮廓的端点数 判断是什么图形
//            cout <<"端点数 "<< conPoly[i].size() << endl;
//
//            //返回包覆输入信息的最小正矩形
//            boundRect[i] = boundingRect(conPoly[i]);
//
//            int objCor = conPoly[i].size();
//            if (objCor == 3) objectType = "Tri";
//            else if (objCor == 4)
//            {
//                float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
//                cout << boundRect[i].width<<" "<< boundRect[i].height <<"长宽之比 " << aspRatio << endl;
//                if(aspRatio>0.95 && aspRatio<1.05) objectType = "Square";
//                else objectType = "Rect";
//            }
//            else objectType = "Circle";
//
//            drawContours(imgOG, conPoly, i, Scalar(255, 0, 255), 2);
//            
//            rectangle(imgOG, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0),2);
//            
//            putText(imgOG, objectType, {boundRect[i].x,boundRect[i].y-5}, FONT_HERSHEY_PLAIN, 1, Scalar(0, 69, 255), 1);
//
//        }
//    }
//}
//
//void main()
//{
//    string path = "Resources/shapes.png";
//    Mat img = imread(path);
//    //灰度图像
//    cvtColor(img, imgGray, COLOR_BGR2GRAY);
//    //去噪
//    GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
//    //边缘检测
//    Canny(imgBlur, imgCanny, 25, 75);
//    //膨胀
//    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
//    dilate(imgCanny, imgDil, kernel);
//
//    //膨胀图上提取边缘 在原图上画出边缘
//    getContours(imgDil,img);
//
//    imshow("测试opencv", img);
//    //imshow("灰度图像", imgGray);
//    //imshow("去噪", imgBlur);
//    //imshow("边缘检测", imgCanny);
//    //imshow("膨胀", imgDil);
//
//    waitKey(0); 
//}