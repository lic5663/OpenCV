#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	//Mat image = imread("images/dilation.jpg", IMREAD_GRAYSCALE);
	Mat image = imread("images/erosion.jpg", IMREAD_GRAYSCALE);
	CV_Assert(image.data);

	Mat th_img, dst, dst2;
	threshold(image, th_img, 128, 255, THRESH_BINARY);

	uchar data[] = {
		0,1,0,
		1,1,1,
		0,1,0
	};

	uchar data2[] = {
		0,0,1,0,0,
		0,0,1,0,0,
		1,1,1,1,1,
		0,0,1,0,0,
		0,0,1,0,0
	};

	Mat mask(3, 3, CV_8UC1, data);
	morphologyEx(th_img, dst, MORPH_DILATE, mask);

	Mat mask3(3, 3, CV_8UC1, data);
	morphologyEx(th_img, dst2, MORPH_ERODE, mask);

	//Mat mask2(5, 5, CV_8UC1, data2);
	//morphologyEx(th_img, dst2, MORPH_DILATE, mask2);



	imshow("image", image);
	imshow("binary", th_img);
	imshow("Dilation", dst);
	imshow("Erosion", dst2);
	//imshow("Dilation2", dst2);
	waitKey();

	return 0;
}