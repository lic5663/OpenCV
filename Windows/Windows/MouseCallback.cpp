#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void onMouse(int, int, int, int, void*);

int main()
{
	Mat image(200, 300, CV_8U);
	image.setTo(255);

	imshow("���콺 �̺�Ʈ1", image);
	imshow("���콺 �̺�Ʈ2", image);
	int a = 10;

	setMouseCallback("���콺 �̺�Ʈ1", onMouse, &a);
	setMouseCallback("���콺 �̺�Ʈ2", onMouse, &a);
	waitKeyEx(0);

	return 0;
}

void onMouse(int event, int x, int y, int flags, void* param)
{
	switch (event)
	{
	case EVENT_LBUTTONDOWN:
		cout << "���콺 ���� ��ư ������ -- " << *(int*)param << endl;
		break;
	case EVENT_RBUTTONDOWN:
		cout << "���콺 ������ ��ư ������" << endl;
		break;
	case EVENT_RBUTTONUP:
		cout << "���콺 ������ ��ư ����" << endl;
		break;
	case EVENT_LBUTTONDBLCLK:
		cout << "���콺 ���� ��ư ���� Ŭ��" << endl;
		break;
	default:
		break;
	}
}