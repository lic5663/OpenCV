#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat image = imread("images/pixel_test.jpg", IMREAD_GRAYSCALE);
	if (image.empty())
	{
		cout << "영상 읽기 실패" << endl;
		exit(1);
	}

	Rect roi(500, 313, 20, 15);
	Mat roi_img = image(roi);
	cout << "[roi_img] = " << endl;
	for (int i = 0; i < roi_img.rows; i++)
	{
		for (int j = 0; j < roi_img.cols; j++)
		{
			cout.width(5);
			cout << (int)roi_img.at<uchar>(i, j);
		}
		cout << endl;
	}
	rectangle(image, roi, Scalar(255), 1);
	imshow("image", image);
	waitKey();

	return 0;
}