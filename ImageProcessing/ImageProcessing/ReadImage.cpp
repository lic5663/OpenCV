#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(void)
{
	FileStorage fs_read("file/test.xml", FileStorage::READ);
	CV_Assert(fs_read.isOpened());

	FileNode node_pic = fs_read["picture"];
	vector<Mat> images;
	for (int i = 0; i < node_pic.size(); i++)
	{
		Mat tmp = imread("images/" + (string)node_pic[i], IMREAD_UNCHANGED);
		CV_Assert(tmp.data);
		images.push_back(tmp);
		imshow(node_pic[i], images[i]);
	}

	FileStorage fs_write("file/result.xml", FileStorage::WRITE);
	CV_Assert(fs_write.isOpened());

	vector<double> mean, dev;
	for (int i = 0; i < images.size(); i++)
	{
		string pic_name = ((string)node_pic[i]).substr(0, 4);

		meanStdDev(images[i], mean, dev); // 평균과 표준편차를 벡터로 변환
		fs_write << pic_name + "_mean" << "[";
		for (int j = 0; j < mean.size(); j++)
		{
			fs_write << mean[j];
		}
		fs_write << "]";
		fs_write << pic_name + "_dev" << dev;
	}

	waitKey();
	fs_read.release();
	fs_write.release();

	return 0;

}