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
//////����ͼ����ȡ��Ե ��ԭͼ�ϻ�����Ե
//void getContours(Mat imgDilate,Mat imgOG)
//{
//    vector<vector<Point>> contours; //������Ϣ ��Ե��
//    vector<Vec4i> hierarchy; //�㼶��ϵ ��һ��������š���һ��������š���������š����������
//
//    //mode ���������㷨��ģʽ ��ȡ�����Ĳ㼶��Ϣ
//    //RETR_EXTERNALģʽ��ֻ������������
//    //RETR_LISTģʽ���ҵ����е����������ǲ��ṩ�㼶��ϵ
//    //RETR_CCOMPģʽ���ҵ������������㼶ֻ�����㣨�������Ͷ�����������������������������
//    //RETR_TREEģʽ������״�������������Ĺ�ϵ
//
//    //method��Ϸ���
//    //CHAIN_APPROX_NONE�ǲ������� 
//    //CHAIN_APPROX_SIMPLE�Ὣֱ�ߺͶԽ����Ż��� ����Ʋ�඼ѹ����ֻʣ�¶���
//    //CHAIN_APPROX_TC89_L1��CHAIN_APPROX_TC89_KCOS�����˽����㷨
//    
//    findContours(imgDilate, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
//    
//    //                        -1������������
//    //drawContours(imgOG, contours, -1, Scalar(255, 0, 255), 2);
//
//    //ȥ������ ��������������
//    vector<vector<Point>> conPoly(contours.size());//�ǵ� ����4�� Բ�ܶ��
//    vector<Rect> boundRect(contours.size()); //���ο������
//    string objectType; //��������
//    for (int i = 0; i < contours.size(); i++)
//    {
//        //�������
//        double area = contourArea(contours[i]);
//        cout << "������� "<<area << endl;
//        //ȥ������
//        if (area > 1000)
//        {
//            //�������������ܳ������ߵĳ��� true��ʾ���߱պ�
//            float peri = arcLength(contours[i], true);
//            
//            //��һ�������⻬�������߻�
//            //���������� ԭʼ�������������֮���������
//            //������ڴ���ֵ��������С��������epsilonԽС�����ߵ���״Խ���ӽ�������
//            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
//            
//            //�������Ķ˵��� �ж���ʲôͼ��
//            cout <<"�˵��� "<< conPoly[i].size() << endl;
//
//            //���ذ���������Ϣ����С������
//            boundRect[i] = boundingRect(conPoly[i]);
//
//            int objCor = conPoly[i].size();
//            if (objCor == 3) objectType = "Tri";
//            else if (objCor == 4)
//            {
//                float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
//                cout << boundRect[i].width<<" "<< boundRect[i].height <<"����֮�� " << aspRatio << endl;
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
//    //�Ҷ�ͼ��
//    cvtColor(img, imgGray, COLOR_BGR2GRAY);
//    //ȥ��
//    GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
//    //��Ե���
//    Canny(imgBlur, imgCanny, 25, 75);
//    //����
//    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
//    dilate(imgCanny, imgDil, kernel);
//
//    //����ͼ����ȡ��Ե ��ԭͼ�ϻ�����Ե
//    getContours(imgDil,img);
//
//    imshow("����opencv", img);
//    //imshow("�Ҷ�ͼ��", imgGray);
//    //imshow("ȥ��", imgBlur);
//    //imshow("��Ե���", imgCanny);
//    //imshow("����", imgDil);
//
//    waitKey(0); 
//}