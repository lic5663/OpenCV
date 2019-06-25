#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void differOp(Mat img, Mat& dst, int mask_size)
{
	dst = Mat(img.size(), CV_8U, Scalar(0));
	Point h_m(mask_size / 2, mask_size / 2);
	int mask_length = mask_size * mask_size;

	for (int i = h_m.y; i < img.rows - h_m.y; i++)
	{
		for (int j = h_m.x; j < img.cols - h_m.x; j++)
		{
			vector<uchar> mask(mask_length, 0);
			for (int k = 0, s= 0; k < mask_size; k++)
			{
				for (int t = 0; t < mask_size; t++, s++)
				{
					int y = i + k - h_m.y;
					int x = j + t - h_m.x;
					mask[s] = img.at<uchar>(y, x);
				}
			}
			uchar max = 0;
			for (int k = 0; k < mask_length / 2; k++)
			{
				int start = mask[k];
				int end = mask[mask_length - k - 1];

				uchar difference = abs(start - end);
				if (difference > max)
					max = difference;
			}
			dst.at<uchar>(i, j) = max;
		}
	}
}

int main(void)
{
	Mat image = imread("images/pepe.jpg", IMREAD_GRAYSCALE);
	CV_Assert(image.data);

	Mat edge3;
	differOp(image, edge3, 50);

	Mat edge5;
	differOp(image, edge5, 100);

	imshow("image", image);
	imshow("edge3", edge3);
	imshow("edge5", edge5);
	waitKey();

	return 0;
}