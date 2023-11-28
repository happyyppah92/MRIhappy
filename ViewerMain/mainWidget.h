
#ifndef MainWidget_H
#define MainWidget_H

#include "newAcquiretab.h"
#include "newKSpaceTab.h"
#include "newPhysicsTab.h"
#include "myJobItem.h"

#include <QItemSelection>
#include <QTabWidget>
#include <QProxyStyle>
#include <QStyleOptionTab>
#include <QLabel>

//主窗口的主界面
class MainWidget : public QTabWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);

public slots:
	void tabChanged(int);

signals:
    
public:
    void setupTabs();

    NewAquireTab *AcquireTab;
    NewKspaceTab *KSpaceTab;
	NewPhysicsTab *PhysicsTab;

private:
	void tranDataFromAcq2kspace();
	void tranDataFromAcq2physic();
	unsigned int physicTabIdx = 1;
	unsigned int kspaceTabIdx = 2;
};


#endif // MainWidget_H
