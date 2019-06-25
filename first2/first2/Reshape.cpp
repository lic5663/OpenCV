#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

// reshape(int cn, int rows) ä�� ����, row ����
// ���� �� ���� ��� ��ü ���� ���� �¾ƾ��Ѵ�.

// create(int rows, int cols, int type, int ndims, int * sizes)
// ������ �����ϴ� ����� ����, ��, ��, �ڷ����� �����Ͽ� �ٽ� ����
// ���� ��İ� ũ��� �ڷ����� �ٸ��� ���� �޸𸮸� �����ϰ� ���ο� �����͸� ����

void print_matInfo(String m_name, Mat m)
{
	
	cout << "[" << m_name << " ���]" << endl;
	cout << m_name << " = " << endl << m << endl;
	cout << "  ä�� �� = " << m.channels() << endl;
	cout << "  �� X �� = " << m.rows << " X " << m.cols << endl << endl;
}

int main(void)
{
	Mat m1(2, 6, CV_8U, 10);
	Mat m2 = m1.reshape(2);
	Mat m3 = m1.reshape(3, 2);

	print_matInfo("m1(2,6)", m1);
	print_matInfo("m2 = m1.reshape(2)", m2);
	print_matInfo("m3 = m1.reshape(3,2)", m3);

	m1.create(2, 6, CV_8U);
	print_matInfo("m1.create(2,6,CV_8U)", m1);

	m1.create(3, 5, CV_8U);
	print_matInfo("m1.create(3,5,CV_8U)", m1);

	m1.create(3, 5, CV_16S);
	print_matInfo("m1.create(3,5,CV_16S)", m1);

	
}