//#include<iostream>
//#include<opencv2/imgproc.hpp>
//#include<opencv2/highgui.hpp>
//#include<opencv2/objdetect.hpp>
//
//using namespace std;
//using namespace cv;
//
//
///////////////    Face detection//////////////
//
//void main()
//{
//	string path = "Resources/test.png";
//    Mat img = imread(path);
//    
//    CascadeClassifier faceCascade; //级联分类器
//    faceCascade.load("Resources/haarcascade_frontalface_default.xml");
//
//    if (faceCascade.empty())
//        cout << "XML file not loaded" << endl;
//
//    vector<Rect>faces;
//    //检测出图片中所有的人脸，并将人脸用vector保存各个人脸的坐标、大小
//    //image--待检测图片，一般为灰度图像加快检测速度；
//    //objects--被检测物体的矩形框向量组，其中每个矩形包含被检测的对象，矩形可以部分位于原始图像之外
//    //scaleFactor--表示在前后两次相继的扫描中，搜索窗口的比例系数。默认为1.1即每次搜索窗口依次扩大10%;
//    //minNeighbors--指定每个候选矩形需要保留多少个相邻矩形，表示构成检测目标的相邻矩形的最小个数(默认为3个)。
//    //如果组成检测目标的小矩形的个数和小于 min_neighbors - 1 都会被排除。
//     faceCascade.detectMultiScale(img, faces, 1.1, 10);
//
//    for (int i = 0; i < faces.size(); i++)
//    {
//        rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
//    }
//
//    imshow("测试opencv", img);
//
//    waitKey(0);
//}