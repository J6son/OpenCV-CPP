//#include<iostream> 
//#include <opencv2/imgproc.hpp> 
//#include <opencv2/highgui.hpp> 
//
//using namespace cv;
//using namespace std;
//
//////////////Warp///////////////////
//
//float w = 250, h = 350; //牌的大小
//Mat matrix, imgWarp;
//
//void main()
//{
//    string path = "Resources/cards.jpg";
//    Mat img = imread(path);
//    
//    Point2f srcK[4] = { {529,142},{771,190},{405,395}, {674,457} };
//    Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };
//
//    //根据输入和输出点获得图像透视变换的矩阵
//    //将成像投影到一个新的视平面 也称作投影映射
//    //倾斜的图 变为 俯视图
//    matrix = getPerspectiveTransform(srcK, dst);
//    warpPerspective(img, imgWarp, matrix, Point(w, h));
//
//    for (int i = 0; i < 4; i++)
//    {
//        circle(img, srcK[i], 10, Scalar(0, 0, 255), FILLED);
//    }
//
//    imshow("测试opencv", img);
//    imshow("card", imgWarp);
//
//    waitKey(0);
//
//    
//}