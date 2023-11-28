#include "mainWindow.h"

#include <QApplication>
#include <QTranslator>
#include <QFont>
#include <QFile>
#include <QtDebug>

int main(int argc, char *argv[])
{
    // APP 在最上面
    QApplication app(argc, argv);
    app.setQuitOnLastWindowClosed(true);
    app.setOrganizationName("MRITeaching");
    app.setOrganizationDomain("none.com");
    app.setApplicationName("MRITeaching");

    QTranslator t;
    t.load("dicomviewer_cn.qm");
    app.installTranslator(&t);

    //加载主题文件
    QFile themeFIle(":/qss/Resources/mytheme.qss");
    if (themeFIle.exists() )
    {
        qDebug()<< "theme File read OK";
          themeFIle.open(QFile::ReadOnly);
          QString styleSheet = QString::fromUtf8(themeFIle.readAll());
          app.setStyleSheet(styleSheet);
          themeFIle.close();
     }
    MainWindow mainwindow;
    mainwindow.showMaximized();
    return app.exec();
}
