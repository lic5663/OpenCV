#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(void)
{
	Mat m = Mat::eye(10, 10, CV_32FC1);
	cout << "Element (3,3) is " << m.at<float>(3, 3) << endl;

	Mat m2 = Mat::eye(10, 10, CV_32FC2);
	cout << "Element (3,3) is ( " << m2.at<Vec2f>(3, 3)[0] << ", " << m2.at<Vec2f>(3, 3)[1] << " )" << endl;

	Mat m3 = Mat::eye(10, 10, traits::Type<Complex<float>>::value);
	cout << "Element(3,3) is " << m3.at<Complexf>(3, 3).re << " +  " << m3.at<Complexf>(3, 3).im  << "i"<< endl;
	
	cout << "==============================================================================================" << endl;
	int sz[3] = { 4,4,4 };
	Mat m4(3, sz, CV_32FC3); // 크기가 4 4 4 인 3차원 배열
	randu(m4, -10.0f, 10.0f); // -1.0 ~ 1.0 사이 난수 채우기
	//cout << m4 << endl;

	float max = 0.0f;
	MatConstIterator_<Vec3f> it = m4.begin<Vec3f>();
	float len2;
	while (it != m4.end<Vec3f>())
	{
		cout << (*it)[0] << ", " << (*it)[1] << ", " << (*it)[2] << endl;
		len2 = (*it)[0] * (*it)[0] + (*it)[1] * (*it)[1] + (*it)[2] * (*it)[2];
		cout  << "len = " << len2 << endl;
		if (len2 > max)
		{
			max = len2;
		}
			
		it++;
	}
	cout << "max = " << max << endl;


	return 0;
}