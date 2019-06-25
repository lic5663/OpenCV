#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void)
{
	Mat ch0(3, 4, CV_8U, Scalar(10));
	Mat ch1(3, 4, CV_8U, Scalar(20));
	Mat ch2(3, 4, CV_8U, Scalar(30));
	Mat ch_012;

	vector<Mat> vec_012;
	vec_012.push_back(ch0);
	vec_012.push_back(ch1);
	vec_012.push_back(ch2);
	merge(vec_012, ch_012);

	Mat ch_13(ch_012.size(), CV_8UC2);
	Mat ch_2(ch_012.size(), CV_8UC1);
	Mat out[] = { ch_13, ch_2 };
	int from_to[] = { 0,0,2,1,1,2 }; // 홀수 : 소스 , 짝수 : 목적지
	mixChannels(&ch_012, 1, out, 2, from_to, 3); // (원본대상 주소, 원본 개수, 출력대상, 출력대상 개수, 소스-목적지, 소스-목적지 페어 개수)

	cout << "[cd_123] = " << endl << ch_012 << endl << endl; // 채널순으로 출력된다. (1,1) 에서의 0~2채널 출력 후 다음 원소로 넘어간다
	cout << "[ch_13] = " << endl << ch_13 << endl;
	cout << "[ch_2] = " << endl << ch_2 << endl;

	return 0;
}