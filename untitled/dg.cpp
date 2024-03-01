#include "dg.h"
#include "ui_dg.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

dg::dg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dg)
{
    ui->setupUi(this);

    MainWindow* m = reinterpret_cast<MainWindow *>(parent);
    auto pt = m->get_ui();
}

dg::~dg()
{

    delete ui;
}


