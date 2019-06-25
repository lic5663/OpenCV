#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void)
{
	FileStorage fs("file/test.xml", FileStorage::READ);
	CV_Assert(fs.isOpened());

	string name, address, picture;
	int age;
	fs["address"] >> address;
	fs["name"] >> name;
	fs["age"] >> age;

	cout << "address" << address << endl;
	cout << "name " << name << endl;
	cout << "age " << age << endl;

	FileNode node_pic = fs["picture"];
	FileNode node_score = fs["score"];

	try
	{
		if (node_pic.type() != FileNode::SEQ)
			CV_Error(Error::StsError, "시퀀스 노드가 아닙니다");
		if (!node_score.isMap())
			CV_Error(Error::StsError, "매핑 노드가 아닙니다");
	}
	catch (const std::exception&)
	{
		exit(1);
	}

	cout << "[picture] ";
	cout << (string)node_pic[0] << ", ";
	cout << (string)node_pic[1] << ", ";
	cout << (string)node_pic[2] << endl << endl;

	cout << "[score]" << endl;
	cout << "math " << (int)node_score["math"] << endl;
	cout << "Java " << (int)node_score["Java"] << endl;
	cout << "C " << (int)node_score["C"] << endl;

	Point pt;
	Rect rect;
	Mat mat;
	vector<int> vec;

	fs["vector"] >> vec;
	fs["Point"] >> pt;
	fs["Rect"] >> rect;
	fs["Mat"] >> mat;

	cout << "[vec] = " << ((Mat)vec).t() << endl;
	cout << "[pt] = " << pt << endl;
	cout << "[rect] = " << rect << endl << endl;
	cout << "[mat] = " << endl << mat << endl;

	fs.release();
}