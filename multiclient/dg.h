#ifndef DG_H
#define DG_H

#include <QDialog>

namespace Ui {
class Dg;
}



class Dg : public QDialog
{
    Q_OBJECT

public:
    explicit Dg(QWidget *parent = nullptr);
    ~Dg();

private:
    Ui::Dg *ui;
    Dg *diag;
};

#endif // DG_H
