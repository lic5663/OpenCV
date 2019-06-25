#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
	// Range Ŭ����
	// Range(int start , int end)
	// start <= ���� < end
	// int size() : sub sequence�� ũ�� ��ȯ
	// bool empty() : is sub sequence empty?
	// Range all() : ��ü �������� Range�� ��ȯ

	// Rnage Ŭ������ ������ �����ϰ� Mat Ŭ������ () ������ �Լ��� ���ؼ�
	//����� �����ϸ� �θ� ����� Ư�� �κ��� �����ϴ� ����� ���� �����ϴ�
void print_locateROI(String str, Mat m)
{
	Size size;
	Point pt;
	m.locateROI(size, pt);

	cout << "�θ� ũ�� " << size << ", " << "[" << str << "] = " << m.size() << "from " << pt << endl;
}



int main(void)
{
	Range r1(0, 3), r2(3, 7);
	int data[] =
	{
		10,11,12,13,14,15,16,
		20,21,22,23,24,25,26,
		30,31,32,33,34,35,36,
		40,41,42,43,44,45,46
	};

	//Mat m1, m2;
	//m1 = Mat(4, 7, CV_32S, data);
	//m2 = m1(r1, r2);

	//cout << "[m1�� 2�� ��] = " << m1.row(2) << endl;
	//cout << "[m1�� 1�� ��] = " << endl << m1.col(1) << endl;
	//cout << "[m1�� (0~2�� ���) = " << endl << m1.rowRange(r1) << endl << endl;
	//
	//cout << "[m1] = " << endl << m1 << endl << endl;
	//cout << "[m2] = " << endl << m2 << endl << endl;

	//m2.setTo(50);
	//cout << "[m2] = " << endl << m2 << endl;
	//cout << "[m1] = " << endl << m1 << endl << endl;

	Mat m3(5, 7, CV_32S, data);
	Mat m4 = m3(r1, r2);
	Mat m5 = m3(r1, r1);
	cout << "m3 = " << endl << m3 << endl << endl;
	cout << "m4 = " << endl << m4 << endl << endl;
	cout << "m5 = " << endl << m5 << endl << endl;

	print_locateROI("m4", m4);
	print_locateROI("m5", m5);

	m4.adjustROI(-1, 1, 2, -1);
	m5.adjustROI(0, -1, -2, 2);

	cout << endl << "<���ɿ��� ���� ��>" << endl;
	print_locateROI("m4", m4);
	print_locateROI("m5", m5);
	cout << endl;
	cout << "[���� m2] = " << endl << m4 << endl;
	cout << "[���� m3] = " << endl << m5 << endl;


	return 0;
}