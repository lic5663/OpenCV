#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat image(300, 500, CV_8UC1, Scalar(255));
	Point2f center(250, 150), pts[4];
	Size2f size(300, 100);

	RotatedRect rot_rect(center, size, 30);

	Rect bound_rect = rot_rect.boundingRect();
	rectangle(image, bound_rect, Scalar(0), 1);
	circle(image, rot_rect.center, 1, Scalar(0), 2);
	rot_rect.points(pts); // The order is bottomLeft, topLeft, topRight, bottomRight
	for (int i = 0; i < 4; i++)
	{
		circle(image, pts[i], 4, Scalar(0), 1);
		line(image, pts[i], pts[(i + 1) % 4], Scalar(0), 2);
	}

	imshow("RotatedRect", image);
	waitKey(0);

	return 0;
}