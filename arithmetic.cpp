#include "arithmetic.h"
#include <QString>
#include <QMessageBox>
#include <QVariant>
#include <QLineEdit>

Arithmetic::Arithmetic()
{

}

int Arithmetic::addition(int num1, int num2)
{
    int answer = 0;
    answer = num1 + num2;
    return answer;
}

int Arithmetic::subtraction(int num1, int num2)
{
    int answer = 0;
    answer = num1 - num2;
    return answer;
}

int Arithmetic::multiplication(int num1, int num2)
{
    int answer = 0;
    answer = num1 * num2;
    return answer;
}

int Arithmetic::division(int num1, int num2)
{
    int answer = 0;
    answer = num1 / num2;
    return answer;
}
