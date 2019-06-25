#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat image = imread("images/bright.jpg", IMREAD_GRAYSCALE);
	CV_Assert(!image.empty());

	Mat dst1 = image + 100; // ��� ���꿡�� saturation ������ �ؼ� �����÷ο츦 �ڵ� �������ش�. 
	Mat dst2 = image - 100;
	Mat dst3 = 255 - image;

	Mat dst4(image.size(), image.type());
	Mat dst5(image.size(), image.type());
	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			
			//dst4.at<uchar>(i, j) = image.at<uchar>(i , j) + 100; // ���� ȭ�Ҹ��� ������ ��� overflow ������ ������ �ʴ´�.
			dst4.at<uchar>(i, j) = saturate_cast<uchar>(image.at<uchar>(i, j) + 100); // saturation ������ ���ִ� ����
			dst5.at<uchar>(i, j) = 255 - image.at<uchar>(i , j);
		}
	}

	Rect roi(500, 313, 20, 15);
	Mat roi_img = image(roi);
	cout << "[roi_img] = " << endl;
	for (int i = 0; i < roi_img.rows; i++)
	{
		for (int j = 0; j < roi_img.cols; j++)
		{
			cout.width(5);
			cout << (int)roi_img.at<uchar>(i, j);
		}
		cout << endl;
	}
	rectangle(image, roi, Scalar(0), 1);

	Mat roi_img2 = dst4(roi);
	cout << "[roi_img4] = " << endl;
	for (int i = 0; i < roi_img2.rows; i++)
	{
		for (int j = 0; j < roi_img2.cols; j++)
		{
			cout.width(5);
			cout << (int)roi_img2.at<uchar>(i, j);
		}
		cout << endl;
	}
	rectangle(dst4, roi, Scalar(255), 1);



	imshow("Original", image);
	imshow("dst1 - ���", dst1);
	imshow("dst2 - ��Ӱ�", dst2);
	imshow("dst3 - ������", dst3);
	imshow("dst4 - ȭ�Һ� ���", dst4);
	imshow("dst5 - ȭ�Һ� ������", dst5);
	
	waitKey();

	return 0;
}