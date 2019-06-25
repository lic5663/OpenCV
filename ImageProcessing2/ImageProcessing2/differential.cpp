#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void differential(Mat image, Mat& dst, float data1[], float data2[])
{
	Mat dst1, dst2;
	Mat mask1(3, 3, CV_32F, data1);
	Mat mask2(3, 3, CV_32F, data2);

	//filter(image, dst1, mask1);
	//filter(image, dst2, mask2);
	filter2D(image, dst1, CV_32F, mask1);
	filter2D(image, dst2, CV_32F, mask2);

	magnitude(dst1, dst2, dst);

	dst1 = abs(dst1);
	dst2 = abs(dst2);
	dst.convertTo(dst, CV_8U);
	dst1.convertTo(dst1, CV_8U);
	dst2.convertTo(dst2, CV_8U);
	imshow("dst1", dst1);
	imshow("dst2", dst2);


}

int main(void)
{
	Mat image = imread("images/contrast_test.jpg", IMREAD_GRAYSCALE);
	CV_Assert(image.data);

	float data1[] = {
		-1,0,0,
		0,1,0,
		0,0,0
	};

	float data2[] = {
		0,0,-1,
		0,1,0,
		0,0,0
	};

	Mat dst;
	differential(image, dst, data1, data2);

	imshow("image", image);
	imshow("Robets", dst);

	waitKey();


	return 0;
}