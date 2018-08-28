#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLCDNumber>
#include <QLabel>
#include <QString>
#include <QSpinBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void onbtnPlusClicked();
    void onMinusClicked();
    void onbtnDivideClicked();
    void onbtnCloseClicked();
    void onbtnClearClicked();
    void onbtnMultiplyClicked();

public:
    QPushButton* btnPlus;
    QPushButton* btnMinus;
    QLineEdit* txtNum1;
    QLineEdit* txtNum2;
    QPushButton* btnMultiply;
    QPushButton* btnDivide;
    QLCDNumber* output;
    QPushButton* btnClose;
    QPushButton* btnClear;


    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    };

#endif // MAINWINDOW_H
