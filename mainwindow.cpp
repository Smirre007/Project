#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "arithmetic.h"
#include <QString>
#include <QMessageBox>
#include <QVariant>
#include <QLineEdit>
#include <QCheckBox>
#include <QIcon>


void MainWindow::onbtnPlusClicked()
{
    int num1 = txtNum1->text().toInt();
    int num2 = txtNum1->text().toInt();
    Arithmetic calc;
    //int num1 = txtNum1->value();
    //int num2 = txtNum2->value();
       output->display(
                 QString::number(calc.addition(num1, num2))
                    );

}

void MainWindow::onMinusClicked()
{
    Arithmetic calc;
    int num1 = txtNum1->text().toInt();
    int num2 = txtNum1->text().toInt();
            output->display(
                  QString::number(calc.subtraction(num1, num2))
                    );

}

void MainWindow::onbtnDivideClicked()
{
    Arithmetic calc;
    int num1 = txtNum1->text().toInt();
    int num2 = txtNum1->text().toInt();
    //int num1 = txtNum1->value();
    //int num2 = txtNum2->value();
    if(num2 == 0){
        QCheckBox *cb = new QCheckBox("simplecalculator");
        QMessageBox msgbox;
        msgbox.setText("Attempt to devide by zero!");
        msgbox.setIcon(QMessageBox::Information);
        msgbox.addButton(QMessageBox::Ok);
        msgbox.setDefaultButton(QMessageBox::Cancel);
        msgbox.setCheckBox(cb);
        QCheckBox dontShowCheckBox("Show this message again");
        dontShowCheckBox.blockSignals(true);
        return;
    }
        output->display(
                    QString::number(calc.division(num1, num2))
                    );

}

void MainWindow::onbtnCloseClicked()
{
    this->close();
}

void MainWindow::onbtnClearClicked()
{
        output->display("0");
        txtNum1->clear();
        txtNum2->clear();
}

void MainWindow::onbtnMultiplyClicked()
{
    Arithmetic calc;
    int num1 = txtNum1->text().toInt();
    int num2 = txtNum1->text().toInt();
    //int num1 = txtNum1->value();
    //int num2 = txtNum2->value();
        output->display(
                    QString::number(calc.multiplication(num1, num2))
                    );

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget* w = new QWidget();
    QFormLayout* layout = new QFormLayout();
    w->setLayout(layout);
    output = new QLCDNumber();
    output->setFixedWidth(100);
    txtNum1 = new QLineEdit();  //txtNum1 = new QSpinBox()
    txtNum1->setFixedWidth(100);
    txtNum2 = new QLineEdit();   //txtNum2 = new QSpinBox();
    txtNum2->setFixedWidth(100);

    btnPlus = new QPushButton("+");
    btnMinus = new QPushButton("-");
    btnMultiply = new QPushButton("*");
    btnDivide = new QPushButton("/");
    btnClose = new QPushButton("Close");
    btnClose->setFixedWidth(100);
    btnClear = new QPushButton("Clear");

    connect(btnPlus,SIGNAL(clicked(bool)),this,SLOT(onbtnPlusClicked()));
    connect(btnMinus,SIGNAL(clicked(bool)),this,SLOT(onMinusClicked()));
    connect(btnMultiply,SIGNAL(clicked(bool)),this,SLOT(onbtnMultiplyClicked()));
    connect(btnDivide,SIGNAL(clicked(bool)),this,SLOT(onbtnDivideClicked()));
    connect(btnClose,SIGNAL(clicked(bool)),this,SLOT(onbtnCloseClicked()));
    connect(btnClear,SIGNAL(clicked(bool)),this,SLOT(onbtnClearClicked()));

    layout->addRow(new QLabel(""),btnPlus);
    layout->addRow(txtNum1,btnMinus);

    layout->addRow(txtNum2,btnMultiply);

    layout->addRow(output,btnDivide);

    layout->addRow(btnClose,btnClear);

    setCentralWidget(w);
    setFixedSize(220,250);
}

MainWindow::~MainWindow()
{
    delete ui;
}
