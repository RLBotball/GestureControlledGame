#include "stdafx.h"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include "opencv2/opencv.hpp"


using namespace cv;
using namespace std;
void _getBrightness(const Mat& frame, double& brightness)
{
	Mat temp, color[3], lum;
	temp = frame;

	split(temp, color);

	color[0] = color[0] * 0.299;
	color[1] = color[1] * 0.587;
	color[2] = color[2] * 0.114;


	lum = color[0] + color[1] + color[2];

	Scalar summ = sum(lum);

	//-- percentage conversion factor
	brightness = summ[0] / ((::pow(2, 8) - 1)*frame.rows * frame.cols) * 2;
}

int main(int argc, char** argv)
{
	VideoCapture cap;
	// open the default camera, use something different from 0 otherwise;
	// Check VideoCapture documentation.
	if (!cap.open(2))
		return 0;
	char c = cvWaitKey(1000);
	Mat bg;
	cap >> bg;
	c = cvWaitKey(1000);

	SimpleBlobDetector::Params params;

	// Filter by Area.
	params.filterByArea = true;
	params.minArea = 100;
	params.maxArea = 100000;
	params.filterByCircularity = false;
	params.minCircularity = 0.1;
	params.filterByConvexity = false;
	params.filterByInertia = false;
	params.filterByColor = false;
	//params.minThreshold = 240;
	//params.maxThreshold = 255;
	Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);
	// Detect blobs.
	std::vector<KeyPoint> keypoints;

	for (;;)
	{
		Mat frame;
		cap >> frame;
		if (frame.empty()) break; // end of video stream
		double b = 0;
		_getBrightness(frame, b);
		//cout << b << endl;
		//absdiff(bg, frame, frame);

		Mat HSV;
		Mat threshold;

		cvtColor(frame, HSV, CV_BGR2HSV);
		inRange(HSV, Scalar(20, 40, 40), Scalar(80, 220, 220), threshold);
		imshow("thr", threshold);
		imshow("this is yoou, smile! :)", frame);

		// Read image

		// Set up the detector with default parameters.
		// Setup SimpleBlobDetector parameters.

		detector->detect(threshold, keypoints);
		// Draw detected blobs as red circles.
		// DrawMatchesFlags::DRAW_RICH_KEYPOINTS flag ensures the size of the circle corresponds to the size of blob
		Mat im_with_keypoints;
		drawKeypoints(threshold, keypoints, im_with_keypoints, Scalar(0, 0, 255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);		// Show blobs'
		cout << keypoints.size() << "\n";
		//absdiff(Scalar(255, 255, 255), keypoints, keypoints);
		if (keypoints.size() > 0) { imshow("keypoints", im_with_keypoints); }

		if (waitKey(1) == 27) break; // stop capturing by pressing ESC 

	}
	// the camera will be closed automatically upon exit
	// cap.close();
	return 0;
}
