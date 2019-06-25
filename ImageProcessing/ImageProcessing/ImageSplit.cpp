#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void)
{
	Mat image = imread("images/rainbow2.jpg", IMREAD_COLOR);
	CV_Assert(image.data);

	Mat bgr[3];
	split(image, bgr);
	Mat zero = Mat::zeros(image.size(),CV_8UC1);
	Mat blue[] = { bgr[0], zero, zero };
	Mat green[] = { zero, bgr[1], zero };
	Mat red[] = { zero, zero, bgr[2] };

	Mat blueImage;
	merge(blue, 3, blueImage);
	Mat greenImage;
	merge(green, 3, greenImage);
	Mat redImage;
	merge(red, 3, redImage);


	imshow("image", image);
	imshow("blue channel", bgr[0]);
	imshow("green channel", bgr[1]);
	imshow("red channel", bgr[2]);
	imshow("blue", blueImage);
	imshow("green", greenImage);
	imshow("red", redImage);


	waitKey();

	return 0;
}