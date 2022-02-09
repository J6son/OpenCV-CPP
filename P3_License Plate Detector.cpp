#include<iostream>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/objdetect.hpp>

using namespace std;
using namespace cv;


/////////////  License Plate Detector//////////////

void main()
{
    VideoCapture cap1(1);//默认摄像头
    Mat img;

    if (!cap1.isOpened())
        cout << "capture not opened!!!!!!!!" << endl;
    
    CascadeClassifier plateCascade; //级联分类器
    plateCascade.load("Resources/haarcascade_russian_plate_number.xml");

    if (plateCascade.empty())
        cout << "XML file not loaded!!!!!" << endl;

    vector<Rect>plate;

    while (1) 
    {
        if (!cap1.read(img))
            cout << "image not read!!!!" << endl;

        plateCascade.detectMultiScale(img, plate, 1.1, 10);

        for (int i = 0; i < plate.size(); i++)
        {
            Mat imgCrop = img(plate[i]);
            //imshow(to_string(i), imgCrop);
            imwrite("Resources/Plates/" + to_string(i) + ".png", imgCrop);
            rectangle(img, plate[i].tl(), plate[i].br(), Scalar(255, 0, 255), 3);
        }

        imshow("Image", img);

        waitKey(1);
    }


}