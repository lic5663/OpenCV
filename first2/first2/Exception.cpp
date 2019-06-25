#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// std에도 내부 exception이 존재하고 cv에서도 그 exception을 상속한 exception이 존재

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
			if (a == 2) CV_Error_(Error::StsOutOfRange, ("%s : %d",msg2.c_str(),a)); // CV_Error_ 는 두번째 인자에 format을 사용 가능하다.
			if (a == 3) CV_Error_(Error::StsBadArg, ("%s : %d",msg3.c_str(),a));
			CV_Assert(a != 4); // 안의 내용이 true일때는 오류를 던지지 않는다.
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