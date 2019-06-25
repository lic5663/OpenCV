#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat image = imread("images/morphology3.jpg", IMREAD_GRAYSCALE);
	CV_Assert(image.data);

	Mat th_img, dst1, dst2;
	threshold(image, th_img, 128, 255, THRESH_BINARY);

	Matx<uchar, 3, 3> mask;
	mask << 0, 1, 0,
		1, 1, 1,
		0, 1, 0;

	morphologyEx(th_img, dst1, MORPH_OPEN, mask);
	morphologyEx(th_img, dst2, MORPH_CLOSE, mask);

	imshow("image", image);
	imshow("Opening", dst1);
	imshow("Closiong", dst2);
	waitKey();
	return 0;
}