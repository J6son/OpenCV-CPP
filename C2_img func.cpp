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
//    //��ɫ�ռ�ת�� ת��Ϊ�Ҷ�ͼ��
//    cvtColor(img, imgGray, COLOR_BGR2GRAY);
//
//    //ͼ��ƽ������ ��ֵ����ֵ����˹�˲�
//    //����ͼ�� ���ͼ�� �˲��� x�����׼�� y�����׼��
//    GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
//
//    //��Ե��� canny����
//    //������ֵ1�����ص�ᱻ��Ϊ���Ǳ�Ե��
//    //������ֵ2�����ص�ᱻ��Ϊ�Ǳ�Ե��
//    //����ֵ1����ֵ2֮������ص�, �����2���õ��ı�Ե���ص����ڣ�����Ϊ�Ǳ�Ե��������Ϊ���Ǳ�Ե��
//    Canny(img, imgCanny, 10, 80);
//
//    //����ָ����״�ͳߴ�ĽṹԪ�أ��ں˾���3x3 ֵ����1
//    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));

//    //ͼ������ ��ֲ����ֵ ͼ���еĸ������ֽ������ͣ���ԭͼ����ĸ�������
//    Դͼ�����A �Լ��ṹԪ��B��B��A�����������ƶ���ÿ��λ����B������Ԫ�ص����ֵ�滻B������λ��ֵ
//	  ɨ���ֵͼ���ÿһ�����أ��ýṹԪ�����串�ǵĶ�ֵͼ�������롱���㣬�����Ϊ0���ṹͼ��ĸ�����Ϊ0������Ϊ1��
//	  �������ʹ��ֵͼ������һȦ

//	  dilate(imgCanny, imgDil, kernel);
//    //ͼ����ʴ ��ֲ���Сֵ �������ֱ���ʴ����ԭͼ��С�ĸ�������
//    erode(imgDil, imgErode, kernel);
//
//    imshow("����opencv", img);
//    imshow("�Ҷ�ͼ��", imgGray);
//    imshow("��˹ģ��ͼ��", imgBlur);
//    imshow("��Ե���ͼ��", imgCanny);
//    imshow("ͼ������", imgDil);
//    imshow("ͼ����ʴ", imgErode);
//    
//    waitKey(0);
//
//    
//}