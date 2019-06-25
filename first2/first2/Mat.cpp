#include <opencv2/opencv.hpp>
#include <Windows.h>
using namespace cv;
using namespace std;


int main(void)
{
	float data[] = { 1.2f,2.3f,3.2f,4.5f,5.f,6.5f };

	Mat m1(200, 300, CV_8UC4 , Scalar(250,100,100,255));
	Mat m2(2, 3, CV_8U, Scalar(300));
	Mat m3(2, 3, CV_16S, Scalar(100));
	Mat m4(2, 3, CV_32F, data);

	Size sz(2, 3);
	Mat m5(Size(2, 3), CV_64F);
	Mat m6(sz, CV_32F, data);

	Mat m7 = Mat::ones(3, 5, CV_8UC1);
	Mat m8 = Mat::zeros(3, 5, CV_8UC1);
	Mat m9 = Mat::eye(3, 2, CV_8UC1);

	//cout << "[m1] = " << endl << m1 << endl;
	cout << "[m2] = " << endl << m2 << endl;
	cout << "[m3] = " << endl << m3 << endl;
	cout << "[m4] = " << endl << m4 << endl << endl;
	cout << "[m5] = " << endl << m5 << endl;
	cout << "[m6] = " << endl << m6 << endl;

	cout << "[m7] = " << endl << m7 << endl;
	cout << "[m8] = " << endl << m8 << endl;
	cout << "[m9] = " << endl << m9 << endl;

	int r = 75;
	int g = 150;
	int b = 250;
	int a = 255;

	Mat m10(200, 300, CV_8UC4, Scalar(b, g, r , a));
	imshow("test1", m10);
	

	
	waitKey(0);
}