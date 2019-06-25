#include <opencv2/opencv.hpp>
#include <thread>
#include <Windows.h>

using namespace cv;
using namespace std;

string title = "Wave";
Mat image;
Scalar orange(0, 165, 255), blue(255, 0, 0), magenta(255, 0, 255);

void wave(int x, int y, int r)
{
	while (r > 0)
	{
		circle(image, Point(x, y), r, orange);
		
		r -= 5;
		imshow(title, image);
		waitKey(200);
	}
}

void onMouse(int event, int x, int y, int flags, void* param)
{
	if (event == EVENT_RBUTTONDOWN)
	{
		add(image, 10, image);
	}
	else if (event == EVENT_LBUTTONDOWN)
	{
		thread t(wave, x, y, 30);
	}
}



int main(void)
{
	image = Mat(300, 500, CV_8UC3, Scalar(255,255,255));
	namedWindow(title, WINDOW_AUTOSIZE);

	setMouseCallback(title, onMouse, 0);

	imshow(title, image);
	waitKey(0);

	return 0;
}