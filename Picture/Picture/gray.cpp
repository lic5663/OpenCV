#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void print_matInfo(string name, Mat m)
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

	cout << name;
	cout << format(": depth(%d) channels(%d) -> 자료형 : ", m.depth(), m.channels());
	cout << mat_type << "C" << m.channels() << endl;

}

int main(void)
{
	//string filename = "images/grayApel.jpg";
	//string filename = "images/cat.jpeg";
	string filename = "images/pepe.jpg";

	Mat origin = imread(filename, IMREAD_UNCHANGED);
	Mat gray2gray = imread(filename, IMREAD_GRAYSCALE);
	Mat gray2color = imread(filename, IMREAD_COLOR);
	CV_Assert(gray2gray.data && gray2color.data);

	Rect roi(101, 101, 1, 1);
	cout << "행렬 좌표 (100,100) 화소값" << endl;
	cout << "origin" << origin(roi) << endl;
	cout << "gray2gray" << gray2gray(roi) << endl;
	cout << "gray2color" << gray2color(roi) << endl;

	print_matInfo("origin", origin);
	print_matInfo("gray2gray", gray2gray);
	print_matInfo("gray2color", gray2color);

	imshow("origin", origin);
	imshow("gray2gray", gray2gray);
	imshow("gray2color", gray2color);

	waitKey(0);

	return 0;

}