#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QCheckBox>
#include <QDir>
#include "dg.h"
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QStringListModel>
#include <QFileSystemModel>
#include <QStandardItemModel>
#include "producerconsumer.h"
#include "myserver.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    diag = new Dg(this);


    //TCP Server
    server = new Myserver();
    connect(server, &Myserver::msgFromMyServerToMainWindow, this, &MainWindow::msgFromMyServerToMainWindowHandler);

    if (!server->listen(QHostAddress::Any, 50000)) {
        ui->textEdit->setText("Server could not start:" + server->errorString());
    }
    ui->textEdit->setText("Server started\n");

}


MainWindow::~MainWindow()
{
    delete ui;
}

Ui::MainWindow* MainWindow::get_ui()
{
    return ui;
}

void MainWindow::on_pushButton_clicked()
{

    Producer producer;
    Consumer consumer;

    producer.start();
    consumer.start();

    producer.wait();
    consumer.wait();


}

void MainWindow::msgFromMyServerToMainWindowHandler(const QString &msg)
{
    ui->textEdit->append(msg);
}



