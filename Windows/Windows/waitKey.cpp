#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat image(200, 300, CV_8U, Scalar(255));
	namedWindow("Ű���� �̺�Ʈ", WINDOW_AUTOSIZE);
	imshow("Ű���� �̺�Ʈ", image);

	while (true)
	{
		int key = waitKeyEx(0);
		cout << "���� Ű :" << key << endl;
		if (key == 27) // ESC
			break;
		switch (key)
		{
		case 'a': cout << "a �Է�" << endl;
			break;
		case 'b': cout << "b �Է�" << endl;
			break;
		case 0x41: cout << "A �Է�" << endl;
			break;
		case 66: cout << "B �Է�" << endl;
			break;
		case 2424832: cout << "���� ȭ��ǥ �Է�" << endl;
			break;
		case 2490368: cout << "���� ȭ��ǥ �Է�" << endl;
			break;
		case 2555904: cout << "������ ȭ��ǥ �Է�" << endl;
			break;
		case 2621440: cout << "�Ʒ��� ȭ��ǥ �Է�" << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}