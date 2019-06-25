#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// std���� ���� exception�� �����ϰ� cv������ �� exception�� ����� exception�� ����

int main(void)
{
	String msg1 = "a is one";
	String msg2 = "a is two";
	String msg3 = "a is three";
	int a;

	while (true)
	{
		cout << " input a : ";
		cin >> a;

		try
		{
			if (a == 0) CV_Error(Error::StsDivByZero, "a is zero");
			if (a == 1) CV_Error(Error::StsBadSize, msg1);
			if (a == 2) CV_Error_(Error::StsOutOfRange, ("%s : %d",msg2.c_str(),a)); // CV_Error_ �� �ι�° ���ڿ� format�� ��� �����ϴ�.
			if (a == 3) CV_Error_(Error::StsBadArg, ("%s : %d",msg3.c_str(),a));
			CV_Assert(a != 4); // ���� ������ true�϶��� ������ ������ �ʴ´�.
		}
		catch (cv::Exception & e)
		{
			cout << "Exception code (" << e.code << ") : " << e.what();
			cout << endl;
			if (e.code == Error::StsAssert)
				break;
		}
	}
	return 0;
}