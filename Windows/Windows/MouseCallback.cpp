#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void onMouse(int, int, int, int, void*);

int main()
{
	Mat image(200, 300, CV_8U);
	image.setTo(255);

	imshow("마우스 이벤트1", image);
	imshow("마우스 이벤트2", image);
	int a = 10;

	setMouseCallback("마우스 이벤트1", onMouse, &a);
	setMouseCallback("마우스 이벤트2", onMouse, &a);
	waitKeyEx(0);

	return 0;
}

void onMouse(int event, int x, int y, int flags, void* param)
{
	switch (event)
	{
	case EVENT_LBUTTONDOWN:
		cout << "마우스 왼쪽 버튼 누르기 -- " << *(int*)param << endl;
		break;
	case EVENT_RBUTTONDOWN:
		cout << "마우스 오른쪽 버튼 누르기" << endl;
		break;
	case EVENT_RBUTTONUP:
		cout << "마우스 오른쪽 버튼 떼기" << endl;
		break;
	case EVENT_LBUTTONDBLCLK:
		cout << "마우스 왼쪽 버튼 더블 클릭" << endl;
		break;
	default:
		break;
	}
}