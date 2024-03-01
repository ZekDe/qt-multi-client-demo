//#include "mainwindow.h"

#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include <QMap>
#include <QMapIterator>

#include <QPoint>
#include <QSize>
#include <QRect>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
