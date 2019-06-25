#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void)
{
	Mat image = imread("images/grayApel.jpg", IMREAD_GRAYSCALE);
	double minVal, maxVal;
	minMaxIdx(image, &minVal, &maxVal);

	// 그레이 이미지는 화소값이 커지면 밝아진다.
	double ratio = (maxVal - minVal) / 255.0; // 최대 최소 사이를 구해 255로 나눠 비율 ratio를 구한다.

	// 원본 이미지에 작은값을 빼고 비율로 나눠준다.
	Mat dst = (image - minVal) / ratio *3 ; // 곱하면 대비가차 더 난다

	cout << "최소값 = " << minVal << endl;
	cout << "최대값 = " << maxVal << endl;

	imshow("origin", image);
	imshow("dst", dst);
	waitKey();

	return 0;
}