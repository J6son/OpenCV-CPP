//#include<iostream>
//#include<opencv2/imgproc.hpp>
//#include<opencv2/highgui.hpp>
//
//using namespace std;
//using namespace cv;
//
//
///////////read video and webcam
//
//void main()
//{
//	//string path = "Resources/test_video.mp4";
//	//VideoCapture cap(path);
//
//	VideoCapture cap1(1);//Ä¬ÈÏÉãÏñÍ·
//	Mat img;
//
//	if (!cap1.isOpened())
//		cout << "!!!!!!!!" << endl;
//
//	else
//		cout << "~~~~~~~~~" << endl;
//	
//	while (1)
//	{
//		if (!cap1.read(img))
//			cout << "------------" << endl;
//		
//		imshow("Image", img);
//		waitKey(1);
//	}	
//}