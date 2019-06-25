#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat img8 = imread("images/pepe.jpg", IMREAD_COLOR);
	CV_Assert(img8.data);

	Mat img16, img32;
	img8.convertTo(img16, CV_16U, 65535 / 255.0);
	img8.convertTo(img32, CV_32F, 1 / 255.0f);

	Rect roi(105, 105, 5, 5);
	cout << "img8 青纺狼 老何 " << endl << img8(roi) << endl << endl;
	cout << "img16 青纺狼 老何 " << endl << img16(roi) << endl << endl;
	cout << "img32 青纺狼 老何 " << endl << img32(roi) << endl << endl;

	rectangle(img8, roi, Scalar(0, 0, 0), 1);

	imwrite("images/write_test_16.tif", img16);
	imwrite("images/write_test_32.tif", img32);

	imshow("img8", img8);
	imshow("img16", img16);
	imshow("img32", img32);
	waitKey(0);

	return 0;
}