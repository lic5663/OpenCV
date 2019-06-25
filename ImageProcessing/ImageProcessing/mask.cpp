#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void)
{
	Mat m1(3, 6, CV_8UC1, Scalar(10));
	Mat m2(3, 6, CV_8UC1, Scalar(50));
	Mat m_add1, m_add2, m_div1, m_div2 , m_sub1, m_sub2;
	Mat mask(m1.size(), CV_8UC1, Scalar(0));

	Rect rect(Point(3, 0), Size(3, 3));
	mask(rect).setTo(1);

	add(m1, m2, m_add1);
	add(m1, m2, m_add2, mask); // mask를 넣으면 0인 부분만 연산을 하지 않는다. 양수, 음수 다 연산한다.

	subtract(m1, m2, m_sub1);
	subtract(m1, m2, m_sub1, mask);

	divide(m1, m2, m_div1);
	m1.convertTo(m1, CV_32F);
	m2.convertTo(m2, CV_32F);
	divide(m1, m2, m_div2);

	cout << "[m1] = " << endl << m1 << endl;
	cout << "[m2] = " << endl << m2 << endl;
	cout << "[mask] = " << endl << mask << endl << endl;

	cout << "[m_add1] = " << endl << m_add1 << endl;
	cout << "[m_add2] = " << endl << m_add2 << endl << endl;
	cout << "[m_sub1] = " << endl << m_sub1 << endl;
	cout << "[m_sub2] = " << endl << m_sub2 << endl;
	cout << "[m_div1] = " << endl << m_div1 << endl << endl;
	cout << "[m_div2] = " << endl << m_div2 << endl;

	return 0;
}