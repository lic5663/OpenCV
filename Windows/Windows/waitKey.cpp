#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat image(200, 300, CV_8U, Scalar(255));
	namedWindow("키보드 이벤트", WINDOW_AUTOSIZE);
	imshow("키보드 이벤트", image);

	while (true)
	{
		int key = waitKeyEx(0);
		cout << "누른 키 :" << key << endl;
		if (key == 27) // ESC
			break;
		switch (key)
		{
		case 'a': cout << "a 입력" << endl;
			break;
		case 'b': cout << "b 입력" << endl;
			break;
		case 0x41: cout << "A 입력" << endl;
			break;
		case 66: cout << "B 입력" << endl;
			break;
		case 2424832: cout << "왼쪽 화살표 입력" << endl;
			break;
		case 2490368: cout << "위쪽 화살표 입력" << endl;
			break;
		case 2555904: cout << "오른쪽 화살표 입력" << endl;
			break;
		case 2621440: cout << "아래쪽 화살표 입력" << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}