//#include<iostream> 
//#include <opencv2/imgproc.hpp> 
//#include <opencv2/highgui.hpp> 
//
//using namespace cv;
//using namespace std;
//
//////////////Resize and Crop///////////////////
//
//void main()
//{
//    string path = "Resources/test.png";
//    Mat img = imread(path);
//    Mat imgResize,imgCrop;
//
//    cout << img.size() << endl;
//    //����             �������ش�С ����
//    resize(img, imgResize, Size(), 0.5, 0.5);
//
//    //�ü� ��(200,100)��ʼ ��С300x300
//    Rect rol(200, 100, 300, 300);
//    imgCrop = img(rol);
//
//    imshow("����opencv", img);
//    imshow("Resize", imgResize);
//    imshow("Crop", imgCrop);
//
//    waitKey(0);
//
//    
//}