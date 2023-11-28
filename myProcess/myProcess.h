#ifndef MYPROCESS_H
#define MYPROCESS_H
#include "myprocess_global.h"
#include "global.h"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <QObject>
#include <QtConcurrent>
#include <QVector>
#include <dataMode.h>
#include <QPair>

using namespace cv;
//与数据处理有关的代码，应该保证与界面无关
//double转化成0~255,根据最大值最小值归一化,2D,返回合适的窗窗窗位
MYPROCESS_EXPORT void doubleImageNormal(QVector<double>, unsigned char *imageNorm, QPair<double, double> &win);
//double转化成0~255,根据输入窗宽窗位归一化,2D
MYPROCESS_EXPORT void VectorImageWindow(QVector<double>, unsigned char *imageNorm, QPair<double, double> win);
//根据最大值最小值计算窗宽窗位
MYPROCESS_EXPORT void VectorImageWinCal(QList<QVector<double>> imgVector, QPair<double, double> &win);
//计算回波信号，3D
MYPROCESS_EXPORT void CalEchoSignal(dataMode &data, ParaMRI para, QList<QVector<double>> &imgVector);
MYPROCESS_EXPORT void CalSESignal(dataMode &data, ParaMRI para, QList<QVector<double>> &imgVector);
MYPROCESS_EXPORT void CalSECurve(int PD, int T1, int T2, int TE, int TR, QPair<QVector<double>, QVector<double>> &curve);
MYPROCESS_EXPORT void CalIRSignal(dataMode &data, ParaMRI para, QList<QVector<double>> &imgVector);

MYPROCESS_EXPORT QVector<Mat> FFTParProcess(const Mat &paddedimage, ParaPro curpara);//输入图像，输出2副图像
MYPROCESS_EXPORT void FFTProcess(ParaPro para, Mat& input);
MYPROCESS_EXPORT void cvMat2DataImage(QVector<Mat>  input, DataImage &output);
MYPROCESS_EXPORT void DataImage2cvMat(DataImage image, Mat& output);
MYPROCESS_EXPORT void preProcess(ParaPro para, Mat& inputMultiC);
MYPROCESS_EXPORT void FFTshift(Mat& inputMultiC);//支持多通道


#endif // MYPROCESS_H
