#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void)
{
	Mat ch0(300, 400, CV_8U, Scalar(110));
	Mat ch1(300, 400, CV_8U, Scalar(200));
	Mat ch2(300, 400, CV_8U, Scalar(180));

	Mat bgr_arr[] = { ch0,ch1,ch2};

	Mat bgr;
	merge(bgr_arr, 3, bgr);
	vector<Mat> bgr_vec;
	split(bgr, bgr_vec);

	//cout << "[ch0] = " << endl << ch0 << endl;
	//cout << "[ch1] = " << endl << ch1 << endl;
	//cout << "[ch2] = " << endl << ch2 << endl << endl;

	//cout << "[bgr] = " << endl << bgr << endl << endl;
	//cout << "[bgr_vec[0]] = " << endl << bgr_vec[0] << endl;
	//cout << "[bgr_vec[1]] = " << endl << bgr_vec[1] << endl;
	//cout << "[bgr_vec[2]] = " << endl << bgr_vec[2] << endl;

	imshow("ch0", ch0);
	imshow("ch1", ch1);
	imshow("ch2", ch2);
	imshow("bgr", bgr);
	imshow("bgr_vec[0]", bgr_vec[0]);
	imshow("bgr_vec[1]", bgr_vec[1]);
	imshow("bgr_vec[2]", bgr_vec[2]);

	waitKey();

	return 0;
}