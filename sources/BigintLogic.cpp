#include "include/BigintLogic.h"

BigintLogic::BigintLogic(QObject* parent)
    : QObject { parent }
{
}

void BigintLogic::customBinaryOperation(const QString& operand1, const QString& operand2, std::function<Bigint(Bigint, Bigint)> operation)
{
    const Bigint result = operation(Bigint(operand1.toStdString()), Bigint(operand2.toStdString()));
    if (result.isError()) {
        emit calculationError(QString::fromStdString(result.getErrorString()));
        return;
    }

    emit calculationSuccessful(QString::fromStdString(result.toString()));
}
