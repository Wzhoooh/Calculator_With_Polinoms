#include "../Node/Node.h"
#include "Polinom.h"

Polinom::Polinom(const Polinom& source)
{
    this->coefficients = source.coefficients;
}

Polinom::Polinom(const vector < long double > coefficients)
{
    this->coefficients = coefficients;
}

int Polinom::getNumArguments() const
{
    return 0; /// number of Polinom Arguments
}

Node* Polinom::getValue()
{
    return (Node*)new Polinom(*this);
}

vector < long double > getCoefficients() const
{
    return this->coefficients;
}
