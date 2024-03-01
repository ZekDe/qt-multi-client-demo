#ifndef DG_H
#define DG_H

#include <QDialog>

namespace Ui {
class dg;
}

class dg : public QDialog
{
    Q_OBJECT

public:
    explicit dg(QWidget *parent = nullptr);
    ~dg();


private:
    Ui::dg *ui;
    dg *diag;
};

#endif // DG_H
