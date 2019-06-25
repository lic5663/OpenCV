#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void)
{
	float data[] =
	{
		1, 0 , 2,
		-3, 2, 6,
		-1, -2, 3
	};
	
	Mat m1(3, 3, CV_32F, data);
	Mat m2(Matx13f(6, 30, 8));
	Mat m2_t = m2.t();

	Mat m1_inv = m1.inv(DECOMP_LU);
	Mat x = m1_inv * m2_t;

	cout << "[m1] = " << endl << m1 << endl << endl;
	cout << "[m1_inv] = " << endl << m1_inv << endl << endl;
	cout << "[m2] = " << endl << m2 << endl;
	cout << "[m2_t] = " << endl << m2_t << endl;

	cout << "연립 방적식의 해 x1, x2, x3 = " << x.t() << endl << endl;

	Mat m3(Matx33f(1, 2, 3, 4, 5, 6, 7, 8, 9));
	cout << "[m3] = " << endl << m3 << endl;
	cout << "[m3_t] = " << endl << m3.t() << endl;


	return 0;
}