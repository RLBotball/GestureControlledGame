#include "stdafx.h"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include "GameControl.h"
#include <windows.h>
#include "ControlScheme.h"

using namespace cv;
using namespace std;

#define X 0
#define Y 0

int main(int argc, const char** argv)
{

	Mat img = imread("C:\\Users\\Gil\\Downloads\\Doge.jpg", CV_LOAD_IMAGE_UNCHANGED); //read the image data in the file "MyPic.JPG" and store it in 'img'

	if (img.empty()) //check whether the image is loaded or not
	{
		cout << "Error : Image cannot be loaded..!!" << endl;
		//system("pause"); //wait for a key press
		return -1;
	}

	namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"
	imshow("MyWindow", img); //display the image which is stored in the 'img' in the "MyWindow" window

	waitKey(0); //wait infinite time for a keypress

	destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"

	return 0;
}