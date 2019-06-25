#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;


int main(void)
{
	Mat m1(17, 14, CV_32FC3);
	cout << "���� ��  = " << m1.dims << endl;
	cout << "�� ����  = " << m1.rows << endl;
	cout << "�� ����  = " << m1.cols << endl;
	cout << "��� ũ�� = " << m1.size() << endl << endl;

	cout << "��ü ���� ���� = " << m1.total() << endl;
	cout << "�� ������ ũ�� = " << m1.elemSize() << endl; // ȭ�� ũ�� ��ȯ. ä�μ� * ȭ�Ҵ� byte��
	cout << "ä�δ� �� ������ ũ�� = " << m1.elemSize1() << endl << endl;

	cout << "Ÿ�� = " << m1.type() << endl;
	cout << "((m1.channels() -1) << 3) = " << ((m1.channels() - 1) << 3) << endl;
	cout << "Ÿ��(ä�� ��(3bit)|����(3bit)) = " << ((m1.channels() - 1) << 3) + m1.depth() << endl;
	cout << "���� = " << m1.depth() << endl;
	//#define CV_8U		0
	//#define CV_8S		1
	//#define CV_16U	2
	//#define CV_16S	3
	//#define CV_32S	4
	//#define CV_32F	5
	//#define CV_64F	6
	//#define CV_USRTYPE1	7
	cout << "ä�� = " << m1.channels() << endl << endl;

	cout << "step = " << m1.step << endl;
	cout << "step1() = " << m1.step1() << endl; // �� �࿡ �����Ͱ� 9��


	return 0;
}