#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void)
{
	Mat image = imread("images/pic1.jpg", IMREAD_UNCHANGED);
	CV_Assert(image.data);

	Mat x_axis, y_axis, xy_axis, rep_img, trans_img;
	flip(image, x_axis, 0); // 0 : x축 대칭
	flip(image, y_axis, 1); // 양수 : y축 대칭
	flip(image, xy_axis, -1); // 음수 : 원점 대칭

	repeat(image, 2, 3, rep_img);
	//void cv::repeat(InputArray 	src,
	//	int 	ny,
	//	int 	nx,
	//	OutputArray 	dst
	//) inputArray, outputArray는 범용으로 사용할수 있게 만든 형태. input은 readonly ouput은 writeonly. ny :vertical, nx : horizontal 몇번 카피하냐

	transpose(image, trans_img); // 전치행렬 생성

	imshow("image", image);
	imshow("x_axis", x_axis);
	imshow("y_axis", y_axis);
	imshow("xy_axis", xy_axis);
	imshow("rep_img", rep_img);
	imshow("trans_img", trans_img);
	waitKey(0);
	
}