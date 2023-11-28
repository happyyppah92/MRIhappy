
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mainWidget.h"
#include "dataMode.h"
#include "global.h"

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QStatusBar>

//主窗口
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    QFile currentFile;
    dataMode currentData;//当前的数据


private slots:
    void newPatient();
    void closePatient();
    void close();

    void manual();
    void about();
    void updateStatus(QString msg,msgClassEnum msgclass);

private:
    void createMenus();

    MainWidget *mainWidget;
    QMenu *fileMenu;
    QAction *newpatientAct;
    QAction *closepatientAct;
    QAction *exitAct;

    QMenu *helpMenu;
    QAction *manualAct;
    QAction *aboutAct;

    QLabel *statusLabel; 
	QPoint last_mouse_position;
};

#endif // MAINWINDOW_H
