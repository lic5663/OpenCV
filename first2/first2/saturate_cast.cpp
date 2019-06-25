#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// saturate_cast<_Tp>()
// ���� �������� �÷� ���� ��ȯ, ��� / ���� ����. ������, ������ ������ �پ��� ���� �����
// 8bit ������ ����� ����� ���� �� ����
// �̷��� ����� �������� 8bit�� �����ϱ� ���� ��ȭ���(saturation arithmetics)������ ����Ͽ�
// �������� 8bit ���� �ʰ� �� 0 �Ǵ� 255 �� ����� ������ ����
// OpenCV�� ��� ���꿡 ���ؼ� ��ȭ ��� ������ ���
// �⺻ �ڷ����� ���ؼ��� ��ȭ ����� �����ϵ��� saturate_cast<Tp>() ���ø� �޼ҵ带 ����

int main(void)
{
	Matx<uchar, 2, 2> m1;
	Matx<ushort, 2, 2>m2;

	m1(0, 0) = -50;
	m1(0, 1) = 300;
	m1(1, 0) = saturate_cast<uchar>(-50);
	m1(1, 1) = saturate_cast<uchar>(300);

	m2(0, 0) = -50;
	m2(0, 1) = 80000;
	m2(1, 0) = saturate_cast<uchar>(-50);
	m2(1, 1) = saturate_cast<uchar>(80000);

	cout << "[m1] = " << endl << m1 << endl;
	cout << "[m2] = " << endl << m2 << endl;

	return 0;
}