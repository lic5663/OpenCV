#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;


int main(void)
{
	Mat m1(17, 14, CV_32FC3);
	cout << "차원 수  = " << m1.dims << endl;
	cout << "행 개수  = " << m1.rows << endl;
	cout << "열 개수  = " << m1.cols << endl;
	cout << "행렬 크기 = " << m1.size() << endl << endl;

	cout << "전체 원소 개수 = " << m1.total() << endl;
	cout << "한 원소의 크기 = " << m1.elemSize() << endl; // 화소 크기 반환. 채널수 * 화소당 byte수
	cout << "채널당 한 원소의 크기 = " << m1.elemSize1() << endl << endl;

	cout << "타입 = " << m1.type() << endl;
	cout << "((m1.channels() -1) << 3) = " << ((m1.channels() - 1) << 3) << endl;
	cout << "타입(채널 수(3bit)|깊이(3bit)) = " << ((m1.channels() - 1) << 3) + m1.depth() << endl;
	cout << "깊이 = " << m1.depth() << endl;
	//#define CV_8U		0
	//#define CV_8S		1
	//#define CV_16U	2
	//#define CV_16S	3
	//#define CV_32S	4
	//#define CV_32F	5
	//#define CV_64F	6
	//#define CV_USRTYPE1	7
	cout << "채널 = " << m1.channels() << endl << endl;

	cout << "step = " << m1.step << endl;
	cout << "step1() = " << m1.step1() << endl; // 한 행에 데이터가 9개


	return 0;
}