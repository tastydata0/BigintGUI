#ifndef BIGINTLOGIC_H
#define BIGINTLOGIC_H

#include "Bigint.h"
#include <QObject>
#include <functional>

class BigintLogic : public QObject {
    Q_OBJECT
public:
    explicit BigintLogic(QObject* parent = nullptr);

signals:

    ///
    /// \brief calculationSuccessful
    ///
    void calculationSuccessful(const QString&);

    ///
    /// \brief calculationError
    ///
    void calculationError(const QString&);

public slots:

    ///
    /// \brief add - функция сложения 2 чисел, представленных строками
    /// \details Это перегрузка customBinaryOperation, передающая std::plus в качестве операции.
    /// Подробности см. в описании функции customBinaryOperation.
    /// \param operand1 - первый операнд
    /// \param operand2 - второй операнд
    ///
    inline void add(const QString& operand1, const QString& operand2)
    {
        customBinaryOperation(operand1, operand2, std::plus<Bigint>());
    }

    ///
    /// \brief substract - функция вычитания 2 чисел, представленных строками
    /// \details Это перегрузка customBinaryOperation, передающая std::minus в качестве операции.
    /// Подробности см. в описании функции customBinaryOperation.
    /// \param operand1 - первый операнд, из которого вычитаем
    /// \param operand2 - второй операнд, который вычитаем
    ///
    inline void substract(const QString& operand1, const QString& operand2)
    {
        customBinaryOperation(operand1, operand2, std::minus<Bigint>());
    }

    ///
    /// \brief customBinaryOperation - функция, применяющая переданную бинарную операцию над двумя числами, представленными строками.
    /// \details По завершении при успешом вычислении испускает сигнал calculationSuccessful, передав туда результат вычислений.
    /// Если произошла ошибка, испускает сигнал calculationError.
    /// \param operand1 - первый операнд
    /// \param operand2 - второй операнд
    ///
    void customBinaryOperation(const QString& operand1, const QString& operand2, std::function<Bigint(Bigint, Bigint)> operation);
};

#endif // BIGINTLOGIC_H
