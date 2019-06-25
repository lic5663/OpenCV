#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void)
{
	FileStorage fs("file/test.xml", FileStorage::WRITE);
	string name = "ȫ�浿";
	fs << "name" << name;
	fs << "age" << 21;
	fs << "address" << "Chosun";
	fs << "picture" << "[" << "pic1.jpg" << "pic2.jpg" << "pic3.jpg" << "]";

	fs << "score" << "{";
	fs << "math" << 100;
	fs << "Java" << 90;
	fs << "C" << 95 << "}"; // C++�� �ȵ�. ++�� XML���� �����̶� ���������� ����ȵǰ� ��������

	int data[] = { 1,2,3,4,5,6 };
	vector<int> vec(data, data + sizeof(data) / sizeof(int)); // ������������ ������ ����
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