#pragma once
//��ʾ���ڣ��봦��ֿ�
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
	//�������ݡ�Ҫ��ʾһ��ͼ����д���ݣ��ٸ���
	void updateGraphyData(QList<QVector<double>>curImgVectorList, QPair<int, int> curImageSize);
	void updateAnnoData(AnnoItemGroup myanno, cornerTypeEnum corner);
	void updateMyImage(QPixmap image);
	void updateMyCrossLine(int x, int y);
	void updateMyROI(QList<ROImode > ROIList);
	void updateMyGraphyView();//��������
	void myfitinview();//�Զ�����
	void myAutoWP();//�Զ�����
	void updateMyWin(QPair<double, double>win);//�ֶ�����
	void setLinkstyle(bool stu); //�ӿ�
	void changeIndex(int index);
	void clearGraphyView();

	//����ģʽ���ϼ����ڻ����
	void setZoom(double scale);
	void setLinkWinAdjust(QPair<double, double>win);//��������״̬�µ�����λ
	void setLinkValue(QPoint pos);//��������״̬�»�ȡֵ
	void setLinkFitin();
	void setLinkAutoWin();
	void setLinkMoveImage(QPointF pos);
	//void setLinkChangeIndex(int index);

	//����
	void enableCross(bool isEnable);
	void enablePixchangeMode(bool isEnable);
	void enableSelectMode(bool isEnable);


	QAction *copyImageAct;
	QAction *linkallAct;//��������
	QAction *fitinViewAct;//��С����
	QAction *autoWindowsAct;//�Զ�����λ

	QImage myImage;//��Ӧ��ͼ��,������ֱ��ͼ
	QGraphicsScene *myGraphyScene;//ÿ��Viwer��һ������
	bool isLinkallMode = false;
signals://�ź�����֪ͨ��������
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

private slots://�����Ĳۺ���
	void copyImage_slot();
	void LinkallAct_slot();//linkall������slot
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
	//����ѡ��
	bool isCrossEnable = false;//�ڿ�ʼǰ�Ͷ���
	bool isRoiEnable = false;//�ڿ�ʼǰ�Ͷ���
	bool isLinkAllEnable = true;//�ڿ�ʼǰ�Ͷ���

	//����ֵ����ʾ
	void updateRealValue();
	//���±�ǩ��ʾ
	void updateAnnoView(double totalscale);

	bool isKeyCtrlPressed = false;
	bool isKeyShiftPressed = false;
	bool isMouseLeftPressed = false;
	bool isPixchangeMode = false;
	bool isSelectMode = false;
	bool isCrossItemClear = true;

	QPointF startPosLeft;//��굥��ǰ������
	//�߼���ϵ>myAnno->myAnnoItems

	AnnoItemGroup myAnnoTL;//���Ͻǵ�anno �ж��
	AnnoItemGroup myAnnoBL;//���Ͻǵ�anno �ж��
					
	//��ʾ��Ϊ���
	//1��ͼ���
	//2���ı��� QList <QGraphicsTextItem *> myAnnoItems;//
	//3��ʮ���߲� myCrossItem *crossXline;
	//4��ROI��
	//5ˮӡ��
	QList <QGraphicsTextItem *> myAnnoLastItems;//ֻ��һ��
	QList <QGraphicsTextItem *> myAnnoItems;////�ṹmyAnnoItems->myAnnoLU
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
	QPoint curPointImage;//��ǰ�ĵ�
	QList<ROImode > curROIList;
	int crossX = 0, crossY = 0;
};
