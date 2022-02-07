//#include<iostream>
//#include<opencv2/imgproc.hpp>
//#include<opencv2/highgui.hpp>
//
//using namespace std;
//using namespace cv;
//
///////////virtual painter  ///////////
//
//Mat img;
//vector<vector<int>> newPoint; //{{x,y,0},{x,y,1}} 0 1������ɫ
//
////HSV����Сֵ�����ֵ ������ΪҪ����ɫ
////hmin smin vmin hmax smax vmax
//vector<vector<int>> myColor{ {124,48,117,143,170,255},//purple
//							 {68,72,156,182,126,255}  //green
//};
////BGR�µ���ɫֵ
//vector<Scalar> myColorValue{ {255,0,255},//purple
//							 {0,255,0}//green
//};
//
//////����ͼ����ȡ��Ե ��ԭͼ�ϻ�����Ե
//Point getContours(Mat imgDilate)
//{
//    vector<vector<Point>> contours; //������Ϣ ��Ե��
//    vector<Vec4i> hierarchy; //�㼶��ϵ ��һ��������š���һ��������š���������š����������
//
//    findContours(imgDilate, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
//    
//    //ȥ������ ��������������
//    vector<vector<Point>> conPoly(contours.size());//�ǵ� ����4�� Բ�ܶ��
//    vector<Rect> boundRect(contours.size()); //���ο������
//    string objectType; //��������
//
//    Point myPoint;
//
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
//            //ȡ������������ıߵ��м�λ��
//            myPoint.x = boundRect[i].x + boundRect[i].width / 2;
//            myPoint.y = boundRect[i].y;
//
//            drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
//            rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0),2);
//        }
//    }
//    return myPoint;
//}
//
////����ͷ��ͨ��HSVɸѡ����Ҫ����ɫ
//vector<vector<int>> findColor(Mat img)
//{
//	Mat imgHSV;
//	cvtColor(img, imgHSV, COLOR_BGR2HSV);
//
//	for (int i = 0; i < myColor.size(); i++)
//	{
//		Scalar lower(myColor[i][0], myColor[i][1], myColor[i][2]);
//		Scalar upper(myColor[i][3], myColor[i][4], myColor[i][5]);
//		Mat mask;
//		//������ֵ�ڵ�����ֵ����Ϊ��ɫ��255����������ֵ�����ڵ�����ֵ����Ϊ��ɫ��0��
//		inRange(imgHSV, lower, upper, mask);
//		//imshow(to_string(i), mask);
//
//        Point myPoint = getContours(mask);
//        if (myPoint.x != 0 && myPoint.y != 0)
//            newPoint.push_back({ myPoint.x,myPoint.y,i });
//	}
//    return newPoint;
//
//}
//
////vector<vector<int>> newPoint; //{{x,y,0},{x,y,1}} 0 1������ɫ
////BGR�µ���ɫֵ
////vector<Scalar> myColorValue{ {255,0,255},//purple
////                             {0,255,0}//green
////};
//void drawOnCanvas(vector<vector<int>> newPoint, vector<Scalar> myColorValue)
//{
//    for (int i = 0; i < newPoint.size(); i++)
//    {
//        circle(img, Point(newPoint[i][0], newPoint[i][1]), 10, myColorValue[newPoint[i][2]], FILLED);
//    }
//}
//
//void main()
//{
//	VideoCapture cap1(1);
//
//	if (!cap1.isOpened())
//		cout << "capture not opened!" << endl;
//
//	while (1)
//	{
//		if (!cap1.read(img))
//			cout << "------------" << endl;
//		
//		newPoint =  findColor(img);
//        drawOnCanvas(newPoint,myColorValue);
//
//		imshow("Image", img);
//		waitKey(1);
//	}	
//}