#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void print_matInfo(String name, Mat m)
{
	String mat_type;
	if (m.depth() == CV_8U)
		mat_type = "CV_8U";
	else if (m.depth() == CV_8S)
		mat_type = "CV_8S";
	else if (m.depth() == CV_16U)
		mat_type = "CV_16U";
	else if (m.depth() == CV_16S)
		mat_type = "CV_16S";
	else if (m.depth() == CV_32S)
		mat_type = "CV_32S";
	else if (m.depth() == CV_32F)
		mat_type = "CV_32F";
	else if (m.depth() == CV_64F)
		mat_type = "CV_64F";

	cout << name << " 크기 " << m.size << ", ";
	cout << " 자료형 " << mat_type << "C" << m.channels() << endl;
	cout << m << endl << endl;
}
// Mat::release() 메소드는 행렬 데이터와 관련된 참조 카운터를 감소시킴
// 참조 카운터가 0에 도달하면 행렬 데이터를 해제하고
// 행렬 데이터와 참조 카운터의 포인터는 모두 NULL로 설정하여 메모리를 해제
// 일반적으로 Mat 클래스의 destructor()에 의해 자동으로 호출되기 때문에 명시적으로 호출하는 경우는 드물다.

int main(void)
{
	Mat m1(2, 6, CV_8UC1, Scalar(100));
	Mat m2(3, 3, CV_32S);
	Range r1(0, 2), r2(0, 2);
	Mat m3 = m1(r1, r2);

	print_matInfo("m1", m1);
	print_matInfo("m2", m2);
	print_matInfo("m3", m3);

	m2.release();
	m3.release();
	print_matInfo("m2", m2);
	print_matInfo("m3", m3);
	print_matInfo("m1", m1);

	m1.release();
	print_matInfo("m1", m1);

	return 0;
}