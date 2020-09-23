#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcM = imread("C:/Users/admin/Desktop/messi.jpg");
	cv::Mat deepMat = srcM.clone();
	cv::Mat shallowMat = srcM;
	int height = srcM.rows;
	int width = srcM.cols;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			uchar average = (srcM.at<Vec3b>(i, j)[0] + srcM.at<Vec3b>(i, j)[1] + srcM.at<Vec3b>(i, j)[2]) / 3;
			uchar threshold = 100;
			if (average > threshold)
				average = 255;
			else
				average = 0;
			srcM.at<Vec3b>(i, j)[0] = average;
			srcM.at<Vec3b>(i, j)[1] = average;
			srcM.at<Vec3b>(i, j)[2] = average;
		}
	}
	imshow("srcM", srcM);
	imshow("deepMat", deepMat);
	imshow("shallowMat", shallowMat);
	waitKey(0);
}