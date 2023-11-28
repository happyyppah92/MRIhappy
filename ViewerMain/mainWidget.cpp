// 主界面,菜单下面的那部分
#include "mainWidget.h"
#include "global.h"
#include <QtWidgets>
#include <QFont>


MainWidget::MainWidget(QWidget *parent)
    : QTabWidget(parent)   
{
    setupTabs();
	//建立数据传输通道
	connect(this, SIGNAL(currentChanged(int)), this, SLOT(tabChanged(int)));
}


void MainWidget::setupTabs()
{
    AcquireTab = new NewAquireTab(this);
	KSpaceTab = new NewKspaceTab(this);
	PhysicsTab = new NewPhysicsTab(this);

	addTab(AcquireTab, "Imaging");//index=0
	addTab(PhysicsTab, "Physics");//index=1
    addTab(KSpaceTab, "K-Space");//index=2

    this->tabBar()->setProperty("class","1");//设置为1

    this->setTabPosition(QTabWidget::East);
    this->setTabShape(QTabWidget::Triangular);
}

void MainWidget::tranDataFromAcq2kspace()
{
	//只传递结果数据
	int acqjobsize = AcquireTab->myJobList.size();
	KSpaceTab->myJobList.clear();
	for (int ijob = 0; ijob < acqjobsize; ++ijob)
	{
		myJobItem temp;
		temp = AcquireTab->myJobList.at(ijob);
		temp.curJobData.PDmap.clear();//注意这里的数据不传
		temp.curJobData.T1map.clear();
		temp.curJobData.T2map.clear();
		temp.curJobData.T2Startmap.clear();
		//只传递序列结果
		if (temp.curJobPara.Seqtype == seqTypeEnum::SE)
		{
			KSpaceTab->myJobList.append(temp);
		}
		else if(temp.curJobPara.Seqtype == seqTypeEnum::IR)
		{
			KSpaceTab->myJobList.append(temp);
		}
		temp.curJobResult.clear();
	}
	KSpaceTab->updateData();
}

void MainWidget::tranDataFromAcq2physic()
{
	//只传递原始数据
	if (AcquireTab->myJobList.size() > 0)
	{
		dataMode currentData = AcquireTab->myJobList.at(0).curJobData;
		PhysicsTab->updateData(currentData);
	}

}

void MainWidget::tabChanged(int index)
{
	if (index == kspaceTabIdx)
	{
		tranDataFromAcq2kspace();
	}
	if (index == physicTabIdx)
	{
		tranDataFromAcq2physic();
	}
}
