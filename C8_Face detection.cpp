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
//    CascadeClassifier faceCascade; //����������
//    faceCascade.load("Resources/haarcascade_frontalface_default.xml");
//
//    if (faceCascade.empty())
//        cout << "XML file not loaded" << endl;
//
//    vector<Rect>faces;
//    //����ͼƬ�����е�����������������vector����������������ꡢ��С
//    //image--�����ͼƬ��һ��Ϊ�Ҷ�ͼ��ӿ����ٶȣ�
//    //objects--���������ľ��ο������飬����ÿ�����ΰ��������Ķ��󣬾��ο��Բ���λ��ԭʼͼ��֮��
//    //scaleFactor--��ʾ��ǰ��������̵�ɨ���У��������ڵı���ϵ����Ĭ��Ϊ1.1��ÿ������������������10%;
//    //minNeighbors--ָ��ÿ����ѡ������Ҫ�������ٸ����ھ��Σ���ʾ���ɼ��Ŀ������ھ��ε���С����(Ĭ��Ϊ3��)��
//    //�����ɼ��Ŀ���С���εĸ�����С�� min_neighbors - 1 ���ᱻ�ų���
//     faceCascade.detectMultiScale(img, faces, 1.1, 10);
//
//    for (int i = 0; i < faces.size(); i++)
//    {
//        rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
//    }
//
//    imshow("����opencv", img);
//
//    waitKey(0);
//}