#include "Polinom.h"

Polinom::Polinom(const Polinom& source)
{
    this->coefficients = source.coefficients;
}

Polinom::Polinom(const map_int_LD coefficients)
{
    this->coefficients = coefficients;
}

int Polinom::getNumArguments()
{
    return 0; /// number of Polinom Arguments
}

Node* Polinom::getValue()
{
    return (Node*)new Polinom(*this);
}

map_int_LD Polinom::getCoefficients() const
{
    return this->coefficients;
}
