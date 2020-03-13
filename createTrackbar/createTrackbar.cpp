#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

string window_name = "binaryMat";//宏定义窗口名

void threshold_Mat(int th, void* data)//定义回调函数
{
	cv::Mat src = *(cv::Mat*)(data);//将输入数据转化为Mat格式
	cv::Mat dst;
	threshold(src, dst, th, 255, 0);//二值化
	cv::imshow(window_name, dst);//显示二值化图片
}

int main()
{
	cv::Mat srcMat;
	cv::Mat gryMat;
	int lowTh = 30;//设置初始阈值
	int maxTh = 255;//设置最大阈值
	srcMat = cv::imread("D:\\Files\\2.jpg");//读取图片
	if (!srcMat.data)//判断图片是否读取成功
	{
		std::cout << "图片载入失败！" << endl;
		return 0;
	}
	cvtColor(srcMat, gryMat, CV_BGR2GRAY);//转化为灰度图
	cv::imshow(window_name, gryMat);//显示图片
	createTrackbar("threshold",
		window_name,
		&lowTh,
		maxTh,
		threshold_Mat,
		&gryMat);//生成滑动条
	waitKey(0);
	return 0;
}