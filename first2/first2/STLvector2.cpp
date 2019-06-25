#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void print_vectorInfo(string v_name, vector<int> v)
{
	cout << "[" << v_name << "] = ";
	if (v.empty())
		cout << "벡터가 비었습니다" << endl;
	else
		cout << ((Mat)v).reshape(1, 1) << endl;
	cout << v_name <<".size() = " << v.size() << endl;
}

int main(void)
{
	int arr[] = { 10,20,30,40,50 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

	print_vectorInfo("v1", v1);
	cout << endl;

	v1.insert(v1.begin() + 2, 100);
	print_vectorInfo("v1, insert(2)", v1);
	cout << ".capacity() =" << v1.capacity() << endl << endl;

	v1.erase(v1.begin() + 3);
	print_vectorInfo("v1, erase(3)", v1);
	cout << ".capacity() =" << v1.capacity() << endl << endl;

	v1.clear();
	print_vectorInfo("v1, clear()", v1);
}