// TGMTtemplate.cpp : Defines the entry point for the console application.
//
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

//#include <iostream>
//#include <stdio.h>

using namespace std;
using namespace cv;
#include "stdafx.h"
#include <tchar.h>

int _tmain(int argc, _TCHAR* argv[])
{
	cv::CascadeClassifier cascade = cv::CascadeClassifier("cascade.xml");
	cv::Mat img = cv::imread("2.jpg");
	imshow("ảnh gốc", img);
	Mat mat;
	cvtColor(img, mat, CV_BGR2GRAY);
	cv::imshow("ảnh xám", mat);
	std::vector<cv::Rect> rects;
	cascade.detectMultiScale(mat, rects, 1.1, 3, CV_HAAR_SCALE_IMAGE);
	std::cout << "Detected " << rects.size() << " objects";

	for (int i = 0; i < rects.size(); i++)
	{
		rectangle(img, rects[i], Scalar(0, 0, 255), 3, 8, 0);
	}
	imshow("khoanh vùng đối tượng", img);
	imwrite("222.jpg", img);
	cv::waitKey();
	getchar();
	return 0;
}

