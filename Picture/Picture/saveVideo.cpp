#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void put_string(Mat& frame, string text, Point pt, int value)
{
	text += to_string(value);
	Point shade = pt + Point(2, 2);
	int font = FONT_HERSHEY_SIMPLEX;
	putText(frame, text, shade, font, 0.7, Scalar(0, 0, 0), 2);
	putText(frame, text, pt, font, 0.7, Scalar(120, 200, 90), 2);

}


int main(void)
{
	VideoCapture capture;
	capture.open("video/ring.mp4");
	CV_Assert(capture.isOpened());

	double fps = capture.get(CV_CAP_PROP_FPS);
	int delay = 1000 / fps;
	int frame_cnt = 0;
	Mat frame;

	while (capture.read(frame))
	{
		if (waitKey(delay) >= 0)
			break;

		frame_cnt = capture.get(CV_CAP_PROP_POS_FRAMES);
		if (frame_cnt < 100);
		else if (frame_cnt < 200)
			frame -= Scalar(0, 0, 100); // red 100°¨¼Ò
		else if (frame_cnt < 300)
			frame += Scalar(100, 0, 0); // blue 100 Áõ°¡
		else if (frame_cnt < 400)
			frame = frame * 1.5; // ¹à±â 1.5¹è
		else if (frame_cnt < 500)
			frame = frame * 0.5; // ¹à±â 0.5¹è

		put_string(frame, "frame_cnt", Point(20, 50), frame_cnt);

		imshow("Video", frame);
	}

	return 0;
}