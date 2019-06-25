#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

// clone 기존 행렬 데이터 값을 복사해서 새로운 행렬 생성
// void copyTo() 행렬 데이터를 인자로 입력된 mat 행렬에 복사
// void convertTo(Mat mat, int type, double alpha, double beta)
// 행렬 원소의 데이터 타입을 변경하여 생성한 행렬을 mat에 반환

int main(void)
{
	double data[] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.9,9.9,10,11,12 };
	Mat m1(3, 4, CV_64F, data);
	Mat m2 = m1.clone();
	Mat m3, m4;
	m1.copyTo(m3);
	m1.convertTo(m4, CV_8U);
	

	cout << "m1 = " << endl << m1 << endl << endl;
	cout << "m2 = " << endl << m2 << endl << endl;
	cout << "m3 = " << endl << m3 << endl << endl;
	cout << "m4 = " << endl << m4 << endl << endl;


	return 0;
}