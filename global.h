#ifndef GLOBAL_H
#define GLOBAL_H

#pragma once
#include <QObject>
#include <QVector>
#include <QImage>
#include <QMap>
#include <QString>
#include <QList>

#define APPname "MRI Teaching For HBUST"
#define DEBUG 1
#define statuOK 1
#define statuERROR 0
#define annoFONTSIZE 8
#define annoFONTNAME "Courier New"
#define annoFontWeight 90
#define annoFontWeightsamll 90
#define annoFONTSIZEsamll 8
#define winLevelScale 0.001
#define wheelScale 1.2
#define ROIsizehalf 2
#define TimeInterval 1000 //1ms 有1000个点
#define TEmax 1000
#define TRmax 10000

enum msgClassEnum { GREEN = 1, NORMAL = 2, RED = 3 };//状态栏
enum proStatuEnum { OK = 1, ERR = 2, OTH = 3 };//运行状态
enum seqTypeEnum { SE = 1, IR = 2, GE = 3, PDValue = 4, T1Value = 5, T2Value = 6 };//序列种类,统一序列名与枚举名称一致
const QStringList SEQTYPE = { "SE","IR","GE","PD","T1","T2" };
enum dataFromEnum { mrisimWin = 1, MRIlab = 2, Other = 3 };//数据来源
enum dataTypeEnum { MAP2D = 1, MAP3D = 2, Image2D = 3, Image3D, ImageTime };//数据类型
enum cornerTypeEnum { TL = 1, BL = 2, TR = 3, BR = 4 };
enum reconstructionEnum { phase = 1, real = 2, complex = 3 };
enum phaseDirEnum { A2P = 1, P2A = 2 };

const QStringList USTYPE = { "Zero","Compress","Fill" };
const QStringList SMOOTHTYPE = { "Mean", "Gaussian" };
const QStringList WINDOWTYPE = { "Rect","Rect-R","Circle","Circle-R" };
const QStringList PFTYPE = { "Up","Down","Bilateral" };
const QStringList SUFFIXLIST = { "mri","data" };
const long MAXDATASIZE = 1000 * 500 * 1000;//最大的数据大小
 
#endif // GLOBAL_H
