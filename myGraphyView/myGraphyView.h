#pragma once
//显示窗口，与处理分开
#include "mygraphyview_global.h"

#include "global.h"
#include "./myProcess/myProcess.h"
#include "myCrossItem.h"
#include <QGraphicsView>
#include <QPointF>
#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QPair>
#include <QImage>
#include <QPushButton>
#include <QAction>
#include <QGraphicsRectItem>

class MYGRAPHYVIEW_EXPORT myGraphyView: public QGraphicsView
{
	Q_OBJECT
public:
	myGraphyView(QWidget *parent = 0, bool isLinkAllEnable = true);
	//更新数据。要显示一副图像，先写数据，再更新
	void updateGraphyData(QList<QVector<double>>curImgVectorList, QPair<int, int> curImageSize);
	void updateAnnoData(AnnoItemGroup myanno, cornerTypeEnum corner);
	void updateMyImage(QPixmap image);
	void updateMyCrossLine(int x, int y);
	void updateMyROI(QList<ROImode > ROIList);
	void updateMyGraphyView();//更新所有
	void myfitinview();//自动居中
	void myAutoWP();//自动窗宽
	void updateMyWin(QPair<double, double>win);//手动窗宽
	void setLinkstyle(bool stu); //加框
	void changeIndex(int index);
	void clearGraphyView();

	//联动模式下上级窗口会调用
	void setZoom(double scale);
	void setLinkWinAdjust(QPair<double, double>win);//设置联动状态下调窗框窗位
	void setLinkValue(QPoint pos);//设置联动状态下获取值
	void setLinkFitin();
	void setLinkAutoWin();
	void setLinkMoveImage(QPointF pos);
	//void setLinkChangeIndex(int index);

	//功能
	void enableCross(bool isEnable);
	void enablePixchangeMode(bool isEnable);
	void enableSelectMode(bool isEnable);


	QAction *copyImageAct;
	QAction *linkallAct;//窗口联动
	QAction *fitinViewAct;//大小居中
	QAction *autoWindowsAct;//自动窗宽窗位

	QImage myImage;//对应到图像,用来算直方图
	QGraphicsScene *myGraphyScene;//每个Viwer配一个场景
	bool isLinkallMode = false;
signals://信号用于通知其他窗口
	void linkAllBroadcast_signal(bool stu,double scale,QPointF barPos);
	void linkAllZoom_signal(double scale);
	void linkAllValue_signal(QPoint pos);
	void linkALLMoveImage_signal(QPointF pos);
	void linkAllWinAdjust_signal(QPair<double, double> win);
	void WinAdjust_signal(QPair<double, double> win);
	void linkAllAutoFitin_signal();
	void linkAllAutoWP_signal();
	void AutoWP_signal();
	void linkAllCopyImage_signal();
	void CopyImage_signal();
	void linkAllChangeIndex(int index);

	void pixSelect_signal(QPointF pos);
	void setMyFocus_signal();
	void updatelines_signal(QPointF pos);
	void roiSelect_signal(QPointF pos);

private slots://按键的槽函数
	void copyImage_slot();
	void LinkallAct_slot();//linkall按键的slot
	void autoFitIn_slot();
	void autoWP_slot();

protected:
	virtual void wheelEvent(QWheelEvent *event);
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void focusInEvent(QFocusEvent * event);
	virtual void focusOutEvent(QFocusEvent * event);
	virtual void keyPressEvent(QKeyEvent *event);
	virtual void keyReleaseEvent(QKeyEvent *event);

private:
	//功能选项
	bool isCrossEnable = false;//在开始前就定义
	bool isRoiEnable = false;//在开始前就定义
	bool isLinkAllEnable = true;//在开始前就定义

	//更新值的显示
	void updateRealValue();
	//更新标签显示
	void updateAnnoView(double totalscale);

	bool isKeyCtrlPressed = false;
	bool isKeyShiftPressed = false;
	bool isMouseLeftPressed = false;
	bool isPixchangeMode = false;
	bool isSelectMode = false;
	bool isCrossItemClear = true;

	QPointF startPosLeft;//鼠标单击前的坐标
	//逻辑关系>myAnno->myAnnoItems

	AnnoItemGroup myAnnoTL;//左上角的anno 有多个
	AnnoItemGroup myAnnoBL;//左上角的anno 有多个
					
	//显示分为多层
	//1是图像层
	//2是文本层 QList <QGraphicsTextItem *> myAnnoItems;//
	//3是十字线层 myCrossItem *crossXline;
	//4是ROI层
	//5水印层
	QList <QGraphicsTextItem *> myAnnoLastItems;//只有一个
	QList <QGraphicsTextItem *> myAnnoItems;////结构myAnnoItems->myAnnoLU
	QGraphicsPixmapItem *myMainImageItem;
	QList <myCrossItem*> myXYLineLastItems;
    QList <myCrossItem*> myXYLineItems;
	QList <QGraphicsRectItem *> myROIItemsList;
	myCrossItem *crossXline;
	myCrossItem *crossYline;
									
	double curTotalScale;
	QList<QVector<double>>curImgVectorList;
	QPair<double, double> curWinandPos;
	QPair<int, int> curImageSize;
	int curImageIndex = 0;
	QVector<double> curImgVector;
	QPoint curPointImage;//当前的点
	QList<ROImode > curROIList;
	int crossX = 0, crossY = 0;
};
