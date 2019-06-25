#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

// reshape(int cn, int rows) 채널 개수, row 개수
// 변경 전 후의 행렬 전체 원소 수가 맞아야한다.

// create(int rows, int cols, int type, int ndims, int * sizes)
// 기존에 존재하는 행렬의 차원, 행, 열, 자료형을 변경하여 다시 생성
// 기존 행렬과 크기와 자료형이 다르면 기존 메모리를 해제하고 새로운 데이터를 생성

void print_matInfo(String m_name, Mat m)
{
	
	cout << "[" << m_name << " 행렬]" << endl;
	cout << m_name << " = " << endl << m << endl;
	cout << "  채널 수 = " << m.channels() << endl;
	cout << "  행 X 열 = " << m.rows << " X " << m.cols << endl << endl;
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