#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void)
{
	FileStorage fs("file/test.xml", FileStorage::WRITE);
	string name = "홍길동";
	fs << "name" << name;
	fs << "age" << 21;
	fs << "address" << "Chosun";
	fs << "picture" << "[" << "pic1.jpg" << "pic2.jpg" << "pic3.jpg" << "]";

	fs << "score" << "{";
	fs << "math" << 100;
	fs << "Java" << 90;
	fs << "C" << 95 << "}"; // C++은 안됨. ++은 XML에서 연산이라 정상적으로 실행안되고 오류생김

	int data[] = { 1,2,3,4,5,6 };
	vector<int> vec(data, data + sizeof(data) / sizeof(int)); // 시작지점부터 끝지점 지정
	fs << "vector" << vec;
	Mat m(2, 3, CV_32S, data);
	fs << "Mat" << m;

	Point2d pt(10.5, 200);
	Rect rect(pt, Size(100, 200));
	fs << "Point" << pt;
	fs << "Rect" << rect;

	fs.release();

	return 0;
}