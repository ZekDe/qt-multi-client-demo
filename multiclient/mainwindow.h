#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class Dg;
class Myserver;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow* get_ui();

private slots:
    void on_pushButton_clicked();
    void msgFromMyServerToMainWindowHandler(const QString &msg);

private:
    Ui::MainWindow *ui;

    Dg *diag;
    Myserver *server;
};
#endif // MAINWINDOW_H
