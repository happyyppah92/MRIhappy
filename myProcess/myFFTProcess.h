#pragma once

#include "global.h"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "./myProcess/myProcess.h"
#include <QObject>
#include <QtWidgets>
#include <QtConcurrent>
#include <QVector>
#include <dataMode.h>
#include <QPair>

using namespace cv;
class MYPROCESS_EXPORT myFFTProcess : public QObject
{
	Q_OBJECT

public:
	myFFTProcess(QObject *parent=0);
	~myFFTProcess();

	//计算2DFFT
	void Cal2DFFTandProcess(DataImage input, ParaPro para, DataImage& outData, DataImage& outFFT);

	//输入单张图像
	QProgressDialog dialog;
	ParaPro curpara;
	QFutureWatcher<QVector<Mat>> *ParFFTFutureWatcher;
};
