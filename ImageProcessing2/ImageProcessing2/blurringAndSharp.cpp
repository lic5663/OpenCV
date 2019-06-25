#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void filter(Mat img, Mat& dst, Mat mask)
{
	dst = Mat(img.size(), CV_32F, Scalar(0));
	Point h_m = mask.size() / 2;
	for (int i = h_m.y; i < img.rows - h_m.y; i++)
	{
		for (int j = h_m.x; j < img.cols - h_m.x; j++)
		{
			float sum = 0;
			for (int k = 0; k < mask.rows; k++)
			{
				for (int t = 0; t < mask.cols; t++)
				{
					int y = i + k - h_m.y;
					int x = j + t - h_m.x;
					sum += mask.at<float>(k, t) * img.at<uchar>(y, x);
				}
			}
			dst.at<float>(i, j) = sum;
		}
	}
}

int main(void)
{
	Mat image = imread("images/add2.jpg", IMREAD_GRAYSCALE);
	CV_Assert(image.data);

	// blur mask
	float data[] = {
		1 / 9.f, 1 / 9.f, 1 / 9.f,
		1 / 9.f, 1 / 9.f, 1 / 9.f,
		1 / 9.f, 1 / 9.f, 1 / 9.f
	};

	// sharp mask1
	float data2[] = {
		0,-1,0,
		-1,5,-1,
		0,-1,0
	};

	// sharp mask2
	float data3[] = {
		-1,-1,-1,
		-1,9,-1,
		-1,-1,-1
	};

	Mat mask(3, 3, CV_32F, data);
	Mat blur;
	filter(image, blur, mask);
	blur.convertTo(blur, CV_8U);

	Mat mask2(3, 3, CV_32F, data2);
	Mat sharp;
	filter(image, sharp, mask2);
	sharp.convertTo(sharp, CV_8U);

	Mat mask3(3, 3, CV_32F, data3);
	Mat sharp2;
	filter(image, sharp2, mask3);
	sharp2.convertTo(sharp2, CV_8U);

	imshow("image", image);
	imshow("blur", blur);

	imshow("sharp", sharp);
	imshow("sharp2", sharp2);


	waitKey();
		

	return 0;
}