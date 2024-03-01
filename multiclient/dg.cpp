#include "dg.h"
#include "ui_dg.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

Dg::Dg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dg)
{
    ui->setupUi(this);

    MainWindow* m = reinterpret_cast<MainWindow *>(parent);
    auto pt = m->get_ui();
}

Dg::~Dg()
{
    delete ui;
}
