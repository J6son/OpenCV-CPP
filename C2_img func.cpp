//#include<iostream> 
//#include <opencv2/imgproc.hpp> 
//#include <opencv2/highgui.hpp> 
//
//using namespace cv;
//using namespace std;
//
//////////////Img function///////////////////
//
//void main()
//{
//    string path = "Resources/test.png";
//    Mat img = imread(path);
//    Mat imgGray,imgBlur,imgCanny,imgDil,imgErode;
//
//    //颜色空间转化 转化为灰度图像
//    cvtColor(img, imgGray, COLOR_BGR2GRAY);
//
//    //图像平滑降噪 中值、均值、高斯滤波
//    //输入图像 输出图像 滤波核 x方向标准差 y方向标准差
//    GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
//
//    //边缘检测 canny算子
//    //低于阈值1的像素点会被认为不是边缘；
//    //高于阈值2的像素点会被认为是边缘；
//    //在阈值1和阈值2之间的像素点, 若与第2步得到的边缘像素点相邻，则被认为是边缘，否则被认为不是边缘。
//    Canny(img, imgCanny, 10, 80);
//
//    //返回指定形状和尺寸的结构元素（内核矩阵）3x3 值都是1
//    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));

//    //图像膨胀 求局部最大值 图像中的高亮部分进行膨胀，比原图更大的高亮区域
//    源图像矩阵A 以及结构元素B，B在A矩阵上依次移动，每个位置上B所覆盖元素的最大值替换B的中心位置值
//	  扫描二值图像的每一个像素，用结构元素与其覆盖的二值图像做“与”运算，如果都为0，结构图像的该像素为0，否则为1。
//	  结果就是使二值图像扩大一圈

//	  dilate(imgCanny, imgDil, kernel);
//    //图像侵蚀 求局部极小值 高亮部分被腐蚀，比原图更小的高亮区域
//    erode(imgDil, imgErode, kernel);
//
//    imshow("测试opencv", img);
//    imshow("灰度图像", imgGray);
//    imshow("高斯模糊图像", imgBlur);
//    imshow("边缘检测图像", imgCanny);
//    imshow("图像膨胀", imgDil);
//    imshow("图像侵蚀", imgErode);
//    
//    waitKey(0);
//
//    
//}