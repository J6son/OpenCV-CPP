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
//    //�� HSV ��ɫ�ռ��£��� BGR �����׸���ĳ����ɫ�����壬�����ڷָ�ָ����ɫ�����塣
//    //Hue��ɫ����ɫ�ࣩSaturation�����Ͷȡ�ɫ�ʴ����ȣ�Value�����ȣ�
//    //�� GRB�� ��ɫ(255,255,0)����HSV�У���ɫֻ��һ��ֵ������Hue=60���ɡ�
//    //���Ͷȱ�ʾ��ɫ�ӽ�����ɫ�ĳ̶ȡ����Ͷ�Խ�ߣ�˵����ɫԽ�Խ�ӽ�����ɫ���Ͷ�Խ�ͣ�˵����ɫԽǳ��Խ�ӽ���ɫ�����Ͷ�Ϊ0��ʾ����ɫ��
//    //���ȣ�������ɫ�ռ�����ɫ�������̶ȣ�����Խ�ߣ���ʾ��ɫԽ��������Χ�� 0-100%������Ϊ0��ʾ����ɫ
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
//        //�������Ԫ���Ƿ���������������Ԫ��ֵ֮��
//        //������ֵ�ڵ�����ֵ����Ϊ��ɫ��255����
//        //��������ֵ�����ڵ�����ֵ����Ϊ��ɫ��0��
//        Scalar lower(hmin, smin, vmin);
//        Scalar upper(hmax, smax, vmax);
//        inRange(imgHSV, lower, upper, mask);
//
//        imshow("����opencv", img);
//        imshow("HSV", imgHSV);
//        imshow("mask", mask);
//
//        waitKey(1);
//    }
//
//}