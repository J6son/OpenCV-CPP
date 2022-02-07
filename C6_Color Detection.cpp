//#include<iostream> 
//#include <opencv2/imgproc.hpp> 
//#include <opencv2/highgui.hpp> 
//
//using namespace cv;
//using namespace std;
//
//////////////color detection///////////////////
//
//Mat imgHSV, mask;
//int hmin = 0, smin = 0, vmin = 0;
//int hmax = 179, smax = 255, vmax = 255;
//
//void main()
//{
//    string path = "Resources/shapes.png";
//    Mat img = imread(path);
//
//    //在 HSV 颜色空间下，比 BGR 更容易跟踪某种颜色的物体，常用于分割指定颜色的物体。
//    //Hue（色调、色相）Saturation（饱和度、色彩纯净度）Value（明度）
//    //在 GRB中 黄色(255,255,0)；在HSV中，黄色只由一个值决定，Hue=60即可。
//    //饱和度表示颜色接近光谱色的程度。饱和度越高，说明颜色越深，越接近光谱色饱和度越低，说明颜色越浅，越接近白色。饱和度为0表示纯白色。
//    //明度，决定颜色空间中颜色的明暗程度，明度越高，表示颜色越明亮，范围是 0-100%。明度为0表示纯黑色
//    cvtColor(img, imgHSV, COLOR_BGR2HSV);
//
//    namedWindow("Trackbars", (640, 200));
//    createTrackbar("Hue Min", "Trackbars", &hmin, 179);
//    createTrackbar("Hue Max", "Trackbars", &hmax, 179);
//    createTrackbar("Sat Min", "Trackbars", &smin, 255);
//    createTrackbar("Sat Max", "Trackbars", &smax, 255);
//    createTrackbar("Val Min", "Trackbars", &vmin, 255);
//    createTrackbar("Val Max", "Trackbars", &vmax, 255);
//
//    while (1)
//    {    
//        //检查数组元素是否在另外两个数组元素值之间
//        //两个阈值内的像素值设置为白色（255），
//        //而不在阈值区间内的像素值设置为黑色（0）
//        Scalar lower(hmin, smin, vmin);
//        Scalar upper(hmax, smax, vmax);
//        inRange(imgHSV, lower, upper, mask);
//
//        imshow("测试opencv", img);
//        imshow("HSV", imgHSV);
//        imshow("mask", mask);
//
//        waitKey(1);
//    }
//
//}