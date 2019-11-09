#include "Operations.h"

Node* UnaryMinus::getValue(Node* polinom)
{
    Polinom* pointerPolinom = static_cast < Polinom* > (polinom);
    map_int_LD coefficients = pointerPolinom->getCoefficients();

    for (auto& i : coefficients)
        i.second *= -1;

    return (Node*)new Polinom(coefficients);
}
int UnaryMinus::getNumArguments()
{
    return 1;
}

Node* UnaryPlus::getValue(Node* polinom)
{
    return (Node*)new Polinom(*(static_cast < Polinom* > (polinom)));
}
int UnaryPlus::getNumArguments()
{
    return 1;
}

