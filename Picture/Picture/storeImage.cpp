#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(void)
{
	Mat image = imread("images/pepe.jpg", IMREAD_COLOR);
	CV_Assert(image.data);

	vector<int> params_jpg, params_png;
	params_jpg.push_back(IMWRITE_JPEG_QUALITY);
	params_jpg.push_back(50);

	params_png.push_back(IMWRITE_PNG_COMPRESSION);
	params_png.push_back(9);

	imwrite("images/write_tes1.jpg", image);
	imwrite("images/write_tes2.jpg", image, params_jpg);

	imwrite("images/write_tes.png", image, params_png);
	imwrite("images/write_tes.bmp", image);

	return 0;
}
