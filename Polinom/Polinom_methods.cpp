#include "../Node/Node.h"
#include "Polinom.h"

Polinom::Polinom(const Polinom& source)
{
    this->coefficients = source.coefficients;
}

Polinom::Polinom(const vector < long double >& coefficients)
{

}

int Polinom::getNumArguments() const
{
    return 0;
}

Node* getValue();
