#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void)
{
	Mat image = imread("images/grayApel.jpg", IMREAD_UNCHANGED);
	Mat logo = imread("images/logo.jpg", IMREAD_COLOR);
	Mat logo_th, masks[5], background, foreground, dst;
	CV_Assert(image.data && logo.data);

	threshold(logo, logo_th, 70, 255, THRESH_BINARY); // logo에 있는 화소를 logo_th에 저장하는데 화소 기준 70이하면 0, 이상이면 255로 설정해서 저장
	split(logo_th, masks); // masks 0,1,2로 분리

	imshow("mask0", masks[0]);
	imshow("mask1", masks[1]);
	imshow("mask2", masks[2]);

	bitwise_or(masks[0], masks[1], masks[3]);
	bitwise_or(masks[2], masks[3], masks[3]);

	//masks[3] = logo_th;
	bitwise_not(masks[3], masks[4]);

	imshow("logo_th", logo_th);
	imshow("mask3", masks[3]);
	imshow("mask4", masks[4]);

	Point center1 = image.size() / 2;
	Point center2 = logo.size() / 2;
	Point start = center1 - center2;
	Rect roi(start, logo.size());

	bitwise_and(logo, logo, foreground, masks[3]); // 마스크 쓰려고 걍 넣은거 mask인자로는 single channel만 가능하다.
	bitwise_and(image(roi), image(roi), background, masks[4]);

	add(background, foreground, dst);
	dst.copyTo(image(roi));

	imshow("background", background);
	imshow("foreground", foreground);
	imshow("dst", dst);
	imshow("image", image);
	waitKey();


	return 0;
}