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
//vector<vector<int>> newPoint; //{{x,y,0},{x,y,1}} 0 1代表颜色
//
////HSV的最小值和最大值 区间内为要的颜色
////hmin smin vmin hmax smax vmax
//vector<vector<int>> myColor{ {124,48,117,143,170,255},//purple
//							 {68,72,156,182,126,255}  //green
//};
////BGR下的颜色值
//vector<Scalar> myColorValue{ {255,0,255},//purple
//							 {0,255,0}//green
//};
//
//////膨胀图上提取边缘 在原图上画出边缘
//Point getContours(Mat imgDilate)
//{
//    vector<vector<Point>> contours; //轮廓信息 边缘点
//    vector<Vec4i> hierarchy; //层级关系 上一个轮廓序号、下一个轮廓序号、子轮廓序号、父轮廓序号
//
//    findContours(imgDilate, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
//    
//    //去除噪声 不画噪声的轮廓
//    vector<vector<Point>> conPoly(contours.size());//角点 矩形4个 圆很多个
//    vector<Rect> boundRect(contours.size()); //矩形框出轮廓
//    string objectType; //轮廓名称
//
//    Point myPoint;
//
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
//            //取到矩形最上面的边的中间位置
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
////摄像头内通过HSV筛选出需要的颜色
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
//		//两个阈值内的像素值设置为白色（255）而不在阈值区间内的像素值设置为黑色（0）
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
////vector<vector<int>> newPoint; //{{x,y,0},{x,y,1}} 0 1代表颜色
////BGR下的颜色值
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