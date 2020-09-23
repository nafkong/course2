#include<iostream>
#include <opencv2/opencv.hpp>
#include<opencv2/highgui.hpp>
using namespace std;  
using namespace cv;
int main() {
	Mat srcMat = imread("C:/Users/admin/Desktop/messi.jpg");
	int height = srcMat.rows;
	int width = srcMat.cols;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			uchar average = (srcMat.at<Vec3b>(i, j)[0] + srcMat.at<Vec3b>(i, j)[1] + srcMat.at<Vec3b>(i, j)[2]) / 3;
			srcMat.at<Vec3b>(i, j)[0] = average;
			srcMat.at<Vec3b>(i, j)[1] = average;
			srcMat.at<Vec3b>(i, j)[2] = average;
		}
	}
	imshow("src", srcMat);
	waitKey(0);
}
