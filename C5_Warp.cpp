//#include<iostream> 
//#include <opencv2/imgproc.hpp> 
//#include <opencv2/highgui.hpp> 
//
//using namespace cv;
//using namespace std;
//
//////////////Warp///////////////////
//
//float w = 250, h = 350; //�ƵĴ�С
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
//    //����������������ͼ��͸�ӱ任�ľ���
//    //������ͶӰ��һ���µ���ƽ�� Ҳ����ͶӰӳ��
//    //��б��ͼ ��Ϊ ����ͼ
//    matrix = getPerspectiveTransform(srcK, dst);
//    warpPerspective(img, imgWarp, matrix, Point(w, h));
//
//    for (int i = 0; i < 4; i++)
//    {
//        circle(img, srcK[i], 10, Scalar(0, 0, 255), FILLED);
//    }
//
//    imshow("����opencv", img);
//    imshow("card", imgWarp);
//
//    waitKey(0);
//
//    
//}