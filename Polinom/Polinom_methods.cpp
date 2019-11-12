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

const Node& Polinom::getValue() const
{
    return *(new Polinom(*this));
}

int Polinom::getNumArguments() const
{
    return 0; /// number of Polinom Arguments
}

int Polinom::getPriority() const
{
    return MAX_PRIORITY;
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

void Polinom::print(std::ostream& os) const
{
    for (auto it = coefficients.rbegin(); it != coefficients.rend(); it++)
    {
        if (it->second < 0)
            os << " - ";
        else
            if (it != coefficients.rbegin())
                os << " + ";

        os << abs(it->second);

        if (it->first == 0)
            ;
        else if (it->first == 1)
            os << "*x";
        else
            os << "*x^" << it->first;
    }
}
