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

	dst.convertTo(dst, CV_8U);
	//dst1 = abs(dst1);
	//dst2 = abs(dst2);
	//dst1.convertTo(dst1, CV_8U);
	//dst2.convertTo(dst2, CV_8U);

	convertScaleAbs(dst1, dst1); // 위 abs와 convetTo 연산을 한번에 처리
	convertScaleAbs(dst2, dst2);
	//void cv::convertScaleAbs(InputArray src,OutputArray dst, double alpha = 1, double beta = 0)   dst = abs(input * alpha + beta)

	imshow("행 검출", dst1);
	imshow("열 검출", dst2);

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

	float data3[] = {
		-1,-1,-1,
		0,0,0,
		1,1,1
	};

	float data4[] = {
		1,0,-1,
		1,0,-1,
		1,0,-1
	};

	float data5[] = {
		-1,-2,-1,
		0,0,0,
		1,2,1
	};

	float data6[] = {
		1,0,-1,
		2,0,-2,
		1,0,-1
	};

	//Mat roberts;
	//differential(image, roberts, data1, data2);

	//Mat prewitt;
	//differential(image, prewitt, data3, data4);

	Mat sobel;
	differential(image, sobel, data5, data6);

	Mat sobel2, sobel3, sobel4;
	Sobel(image, sobel2, CV_32F, 2, 1, 3);
	Sobel(image, sobel3, CV_32F, 0, 1, 3);
	magnitude(sobel2, sobel3, sobel4);
	sobel4.convertTo(sobel4, CV_8U);
	convertScaleAbs(sobel2, sobel2);
	convertScaleAbs(sobel3, sobel3);

	imshow("image", image);
	//imshow("Robets", roberts);
	//imshow("prewitt", prewitt);
	imshow("sobel", sobel);

	imshow("라이브러리 sobel 수직", sobel2);
	imshow("라이브러리 sobel 수평", sobel3);
	imshow("라이브러리 sobel", sobel4);


	waitKey();


	return 0;
}