#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// saturate_cast<_Tp>()
// 영상 데이터의 컬러 공간 변환, 밝기 / 대조 조정. 샤프닝, 보간법 드으이 다양한 연산 결과가
// 8bit 범위를 벗어나는 결과를 가질 수 있음
// 이러한 결과를 오류없이 8bit로 수용하기 위해 포화산술(saturation arithmetics)연산을 사용하여
// 연산결과가 8bit 범위 초과 시 0 또는 255 중 가까운 값으로 저장
// OpenCV는 행렬 연산에 대해서 포화 산순 연산을 사용
// 기본 자료형에 대해서는 포화 산술이 가능하도록 saturate_cast<Tp>() 템플릿 메소드를 제공

int main(void)
{
	Matx<uchar, 2, 2> m1;
	Matx<ushort, 2, 2>m2;

	m1(0, 0) = -50;
	m1(0, 1) = 300;
	m1(1, 0) = saturate_cast<uchar>(-50);
	m1(1, 1) = saturate_cast<uchar>(300);

	m2(0, 0) = -50;
	m2(0, 1) = 80000;
	m2(1, 0) = saturate_cast<uchar>(-50);
	m2(1, 1) = saturate_cast<uchar>(80000);

	cout << "[m1] = " << endl << m1 << endl;
	cout << "[m2] = " << endl << m2 << endl;

	return 0;
}