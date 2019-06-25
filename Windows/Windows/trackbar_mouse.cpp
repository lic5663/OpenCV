#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


string title = "��� ����";
string bar_name = "��Ⱚ";
string r_value = "R";
string g_value = "G";
string b_value = "B";
Mat image;

void onChange(int value, void* userData)
{
	int add_value = value - 130;
	cout << "�߰� ȭ�Ұ�" << add_value << endl;

	Mat tmp = image + add_value;
	imshow(title, tmp);
}

void onMouse(int event, int x, int y, int flags, void* param)
{
	if (event == EVENT_RBUTTONDOWN)
	{
		add(image, 10, image);
	}
	else if (event == EVENT_LBUTTONDOWN)
	{
		subtract(image, 10, image);
	}
	setTrackbarPos(bar_name, title, image.at<uchar>(0, 0));
	imshow(title, image);
}

int main(void)
{
	int value = 130;
	image = Mat(300, 500, CV_8UC1, Scalar(120));
	namedWindow(title, WINDOW_AUTOSIZE);
	createTrackbar(bar_name, title, &value, 255, onChange);
	createTrackbar(r_value, title, &value, 255, onChange);
	createTrackbar(g_value, title, &value, 255, onChange);
	createTrackbar(b_value, title, &value, 255, onChange);
	setMouseCallback(title, onMouse, 0);

	imshow(title, image);
	waitKey(0);

	return 0;
}