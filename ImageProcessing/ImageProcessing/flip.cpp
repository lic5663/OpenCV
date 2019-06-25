#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void)
{
	Mat image = imread("images/pic1.jpg", IMREAD_UNCHANGED);
	CV_Assert(image.data);

	Mat x_axis, y_axis, xy_axis, rep_img, trans_img;
	flip(image, x_axis, 0); // 0 : x�� ��Ī
	flip(image, y_axis, 1); // ��� : y�� ��Ī
	flip(image, xy_axis, -1); // ���� : ���� ��Ī

	repeat(image, 2, 3, rep_img);
	//void cv::repeat(InputArray 	src,
	//	int 	ny,
	//	int 	nx,
	//	OutputArray 	dst
	//) inputArray, outputArray�� �������� ����Ҽ� �ְ� ���� ����. input�� readonly ouput�� writeonly. ny :vertical, nx : horizontal ��� ī���ϳ�

	transpose(image, trans_img); // ��ġ��� ����

	imshow("image", image);
	imshow("x_axis", x_axis);
	imshow("y_axis", y_axis);
	imshow("xy_axis", xy_axis);
	imshow("rep_img", rep_img);
	imshow("trans_img", trans_img);
	waitKey(0);
	
}