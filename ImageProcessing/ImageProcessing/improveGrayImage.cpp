#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void)
{
	Mat image = imread("images/grayApel.jpg", IMREAD_GRAYSCALE);
	double minVal, maxVal;
	minMaxIdx(image, &minVal, &maxVal);

	// �׷��� �̹����� ȭ�Ұ��� Ŀ���� �������.
	double ratio = (maxVal - minVal) / 255.0; // �ִ� �ּ� ���̸� ���� 255�� ���� ���� ratio�� ���Ѵ�.

	// ���� �̹����� �������� ���� ������ �����ش�.
	Mat dst = (image - minVal) / ratio *3 ; // ���ϸ� ����� �� ����

	cout << "�ּҰ� = " << minVal << endl;
	cout << "�ִ밪 = " << maxVal << endl;

	imshow("origin", image);
	imshow("dst", dst);
	waitKey();

	return 0;
}