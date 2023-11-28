#pragma once

#include <QTableView>
#include <QStandardItemModel>
#include <QList>
#include <QAction>
#include "dataMode.h"

class myRoitableview : public QTableView
{
public:
	myRoitableview(QWidget *parent=0);
	~myRoitableview();

	void setMytable();
	void updateTableView(QList<ROImode> myRoilist);//
	void clearTableView();
	void delectAll();

	QAction *delectItemAct;//����ͼ����
	QAction *delectAllItemAct;
private:
	QStandardItemModel* myDbtableModel;
};
