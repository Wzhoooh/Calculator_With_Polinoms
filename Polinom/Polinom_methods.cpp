#include "Polinom.h"

Polinom::Polinom(const Polinom& source)//: Polinom(source.getCoefficients())
{
    Polinom(source.getCoefficients());
}

Polinom::Polinom(const map_int_LD coefficients)
{
    this->coefficients = coefficients;

    // we are deleting elements with zero coefficients
    for (map_int_LD::iterator i = this->coefficients.begin(); i != this->coefficients.end();)
        if (i->first != 0 && i->second == 0)
            this->coefficients.erase(i++);
        else
            ++i;
}

int Polinom::getNumArguments() const
{
    return 0; /// number of Polinom Arguments
}

const Node& Polinom::getValue() const
{
    return *(new Polinom(*this));
}

const Polinom& Polinom::operator = (const Polinom& source)
{
    this->coefficients = source.coefficients;
    return *(new Polinom(*this));
}

map_int_LD Polinom::getCoefficients() const
{
    return coefficients;
}

void Polinom::print(ostream& os) const
{
    for (auto& i : coefficients)
    {
        os << "+ ";
        if (i.first == 0)
            os << i.second << " ";
        else if (i.first == 1)
            os << i.second << "*x ";
        else
            os << i.second << "*x^" << i.first << " ";
    }
}
