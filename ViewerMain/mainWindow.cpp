// 主界面 带菜单
#include "mainWindow.h"
#include "./MainFrame/aboutDialog.h"
#include "dataMode.h"
#include "myfileopen.h"

#include <QAction>
#include <QFileDialog>
#include <QMenuBar>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QtMath>
#include <QVector>
#include <algorithm>
#include <QStatusBar>
#include <QLabel>
#include <QString>

//APP->MainWindow->MainWidget->tabs

MainWindow::MainWindow(QWidget *parent)
{
	Q_UNUSED(parent)
    mainWidget = new MainWidget;
    setCentralWidget(mainWidget);
    createMenus();
    setWindowTitle(tr(APPname));
	setWindowIcon(QIcon(":/icon/Resources/mri.ico"));


    statusLabel=new QLabel("");
    statusLabel->setMinimumSize(100, 20); // 设置标签最小大小
    statusBar()->addWidget(statusLabel);
    updateStatus("Ready",msgClassEnum::GREEN);

   // setWindowFlags(Qt::FramelessWindowHint);

    //全局的信号--需要传到主界面的信号
    connect(mainWidget->AcquireTab,SIGNAL(updateStatus(QString ,msgClassEnum)),this,SLOT(updateStatus(QString ,msgClassEnum)));
}


void MainWindow::createMenus()
{
    //file 菜单
    fileMenu = menuBar()->addMenu(tr("&Patient"));

    newpatientAct = new QAction(tr("&New Patient..."), this);
    fileMenu->addAction(newpatientAct);
    connect(newpatientAct, &QAction::triggered, this, &MainWindow::newPatient);


    closepatientAct = new QAction(tr("&Close Patient..."), this);
    fileMenu->addAction(closepatientAct);
    connect(closepatientAct, &QAction::triggered, this, &MainWindow::closePatient);


    fileMenu->addSeparator();
    exitAct = new QAction(tr("E&xit"), this);
    fileMenu->addAction(exitAct);
    connect(exitAct, &QAction::triggered, this, &MainWindow::close);


    //help 菜单
    helpMenu = menuBar()->addMenu(tr("&Help"));

    manualAct = new QAction(tr("&Manual"), this);
    helpMenu->addAction(manualAct);
    connect(manualAct, &QAction::triggered, this, &MainWindow::manual);


    helpMenu->addSeparator();
    aboutAct = new QAction(tr("&About"), this);
    helpMenu->addAction(aboutAct);
    connect(aboutAct, &QAction::triggered, this,  &MainWindow::about);
}


//导入数据
void MainWindow::newPatient()
{
    //打开数据
    int isOK;
    myFileOpen myfileopen;
    QString fileName=QFileDialog().getOpenFileName(
                this,
                tr("New Patient"),
                "",
                tr("Patient file(*.mri *.data)"));
    //文件名为空
    if (fileName.isEmpty()) {
        QMessageBox::warning(this, "Warning!", "Failed to Open Patient!");
    }
    else {
        currentFile.setFileName(fileName);
        if(!currentFile.open(QIODevice::ReadOnly))
        {
            updateStatus("File Open:FAILL",msgClassEnum::RED);
        }
        else
        {
            closePatient();
            //读数据currentData
            isOK= myfileopen.rawPatientFileOpen(currentFile,currentData);
            if(isOK==statuOK)
            {

             updateStatus("Open a new Patient:OK",msgClassEnum::GREEN);
             //发送数据给子窗口
             mainWidget->AcquireTab->updateData(currentData);
             if(currentData.dataType==dataTypeEnum::MAP2D || currentData.dataType==dataTypeEnum::MAP3D){
             mainWidget->AcquireTab->newBtn->setEnabled(true);
             }
            }else
            {
             updateStatus("File Read:FAILL",msgClassEnum::RED);
            }
        }
    }
}

void MainWindow::closePatient()
{
    currentData.clear();
    mainWidget->AcquireTab->closepatient();
    updateStatus("Close Patient",msgClassEnum::NORMAL);
}
void MainWindow::close()
{
    QWidget::close();
}
void MainWindow::manual()
{

}

void MainWindow::about()
{
    AboutDialog d(this);
    d.exec();
}

void MainWindow::updateStatus(QString msg,msgClassEnum msgClass)
{

    statusLabel->setText(msg);
    if(msgClass==msgClassEnum::GREEN)
    {
    statusLabel->setStyleSheet("QLabel{color:rgb(0,255,0);}");  //设置样式表
    }
    else if(msgClass==msgClassEnum::NORMAL)
    {
    statusLabel->setStyleSheet("QLabel{color:rgb(255,255,255);}");  //设置样式表
    }
    else
    {
    statusLabel->setStyleSheet("QLabel{color:rgb(255,0,0);}");  //设置样式表
    }
}

