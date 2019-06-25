#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat image1(300, 400, CV_8U, Scalar(255));
	Mat image2(300, 400, CV_8U, Scalar(200));
	Mat image3(300, 400, CV_8U, Scalar(0));
	

	string title1 = "white window";
	string title2 = "gray window";
	string title3 = "dark window";

	namedWindow(title1, WINDOW_AUTOSIZE);
	namedWindow(title2, WINDOW_AUTOSIZE);
	namedWindow(title3, WINDOW_AUTOSIZE);

	moveWindow(title1, 100, 200);
	moveWindow(title2, 525, 200);
	moveWindow(title3, 950, 200);

	imshow(title1, image1);
	imshow(title2, image2);
	imshow(title3, image3);
	waitKey();

	destroyAllWindows();
}