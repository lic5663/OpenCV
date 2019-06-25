#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat image1(50, 512, CV_8UC1, Scalar(0));
	Mat image2(50, 512, CV_8UC1, Scalar(0));

	cout << image1.rows << endl;
	cout << image1.cols << endl;

	for (int i = 0; i < image1.rows; i++)
	{
		for (int j = 0; j < image1.cols; j++)
		{
			image1.at<uchar>(i, j) = j /2;
			image2.at<uchar>(i, j) = (j / 20) * 10;
		}
	}
	imshow("image1", image1);
	imshow("image2", image2);
	waitKey();


	return 0;
}