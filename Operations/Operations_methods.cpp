#include "Operations.h"

#include <iostream>
#include <cstdlib>

const Node& UnaryMinus::getValue(const Node& polinom) const throw(bad_cast)
{
    const Polinom& pointerPolinom = dynamic_cast < const Polinom& > (polinom);
    map_int_LD coefficients = pointerPolinom.getCoefficients();

    for (auto& i : coefficients)
        i.second *= -1;

    return *(new Polinom(coefficients));
}
int UnaryMinus::getNumArguments() const
{
    return 1;
}
void UnaryMinus::print(ostream& os) const
{
    os << "Unary_Minus ";
}

const Node& UnaryPlus::getValue(const Node& polinom) const throw(bad_cast)
{
    return *(new Polinom(dynamic_cast < const Polinom& > (polinom)));
}
int UnaryPlus::getNumArguments() const
{
    return 1;
}
void UnaryPlus::print(ostream& os) const
{
    os << "Unary_Plus ";
}

///----------------------Binary_Operations----------------------///

const Node& BinaryAdd::getValue(const Node& polinomFirst, const Node& polinomSecond) const throw(Too_Big_Number, bad_cast)
{
    const Polinom&  pointerPolinomFirst = dynamic_cast < const Polinom& > (polinomFirst);
    const Polinom& pointerPolinomSecond = dynamic_cast < const Polinom& > (polinomSecond);
    map_int_LD  coefficientsFirst =  pointerPolinomFirst.getCoefficients();
    map_int_LD coefficientsSecond = pointerPolinomSecond.getCoefficients();
    map_int_LD resultedCoefficients = coefficientsFirst;

    for (map_int_LD::iterator itSecond = coefficientsSecond.begin(); itSecond != coefficientsSecond.end(); itSecond++)
    {
        if (resultedCoefficients[itSecond->first] + itSecond->second != 0)
            resultedCoefficients[itSecond->first] += itSecond->second;
        else resultedCoefficients[itSecond->first] = 0;
    }

    return *(new Polinom(resultedCoefficients));
}
int BinaryAdd::getNumArguments() const
{
    return 2;
}
void BinaryAdd::print(ostream& os) const
{
    os << "Binary_Add ";
}

const Node& BinarySub::getValue(const Node& polinomFirst, const Node& polinomSecond) const throw(Too_Big_Number, bad_cast)
{
    BinaryAdd add;
    UnaryMinus minus;
    return add.getValue(polinomFirst, minus.getValue(polinomSecond));
}
int BinarySub::getNumArguments() const
{
    return 2;
}
void BinarySub::print(ostream& os) const
{
    os << "Binary_Sub ";
}

const Node& BinaryMul::getValue(const Node& polinomFirst, const Node& polinomSecond) const throw(Too_Big_Number, Too_Big_Degree, bad_cast)
{
    const Polinom&  pointerPolinomFirst = dynamic_cast < const Polinom& > (polinomFirst);
    const Polinom& pointerPolinomSecond = dynamic_cast < const Polinom& > (polinomSecond);
    map_int_LD  coefficientsFirst =  pointerPolinomFirst.getCoefficients();
    map_int_LD coefficientsSecond = pointerPolinomSecond.getCoefficients();
    map_int_LD resultedCoefficients;

    for (map_int_LD::iterator itFirst = coefficientsFirst.begin(); itFirst != coefficientsFirst.end(); itFirst++)
    {
        for (map_int_LD::iterator itSecond = coefficientsSecond.begin(); itSecond != coefficientsSecond.end(); itSecond++)
        {
            int resultedDegree = itFirst->first + itSecond->first;
            if (resultedDegree > MAX_DEGREE)
                throw Too_Big_Degree();

            long double resultedCoefficient = itFirst->second * itSecond->second;
            if (abs(resultedCoefficient) > MAX_NUMBER)
                throw Too_Big_Number();

            if (resultedCoefficient != 0)
                resultedCoefficients[resultedDegree] += resultedCoefficient;
        }
    }

    return *(new Polinom(resultedCoefficients));
}
int BinaryMul::getNumArguments() const
{
    return 2;
}
void BinaryMul::print(ostream& os) const
{
    os << "Binary_Mul ";
}

const Node& BinaryDiv::getValue(const Node& polinomFirst, const Node& polinomSecond) const throw(Too_Big_Number, Div_By_X, Div_By_Zero, bad_cast)
{
    const Polinom&  pointerPolinomFirst = dynamic_cast < const Polinom& > (polinomFirst);
    const Polinom& pointerPolinomSecond = dynamic_cast < const Polinom& > (polinomSecond);
    map_int_LD  coefficientsFirst =  pointerPolinomFirst.getCoefficients();
    map_int_LD coefficientsSecond = pointerPolinomSecond.getCoefficients();
    map_int_LD resultedCoefficients = coefficientsFirst;

    if (coefficientsSecond.size() != 1 || coefficientsSecond.begin()->first != 0)
        throw Div_By_X();

    long double divider = coefficientsSecond.begin()->second;
    if (abs(divider) < PRECISION) /// 1e-20
        throw Div_By_Zero();

    for (auto& i : resultedCoefficients)
        i.second /= divider;

    return *(new Polinom(resultedCoefficients));
}
int BinaryDiv::getNumArguments() const
{
    return 2;
}
void BinaryDiv::print(ostream& os) const
{
    os << "Binary_Div ";
}

const Node& BinaryPow::getValue(const Node& polinomFirst, const Node& polinomSecond) const throw(Too_Big_Number, Too_Big_Degree, X_In_Degree, Invalid_Degree_Of_X, bad_cast)
{
    const Polinom&  pointerPolinomFirst = dynamic_cast < const Polinom& > (polinomFirst);
    const Polinom& pointerPolinomSecond = dynamic_cast < const Polinom& > (polinomSecond);
    map_int_LD  coefficientsFirst =  pointerPolinomFirst.getCoefficients();
    map_int_LD coefficientsSecond = pointerPolinomSecond.getCoefficients();

    long double degree = coefficientsSecond.begin()->second;

    if (coefficientsSecond.size() != 1 || coefficientsSecond.begin()->first != 0)
        throw X_In_Degree();

    if (degree > MAX_DEGREE)
        throw Too_Big_Degree();

    if ((coefficientsFirst.size() != 1 || coefficientsSecond.begin()->first != 0) && (long long)degree != degree)
        throw Invalid_Degree_Of_X();

    if ((coefficientsFirst.size() != 1 || coefficientsSecond.begin()->first != 0) && degree < 0)
        throw Invalid_Degree_Of_X();

    if (degree == 0)
    {
        map_int_LD coefficientZeroDegree;
        coefficientZeroDegree.insert({0, 1});
        return *( new Polinom(coefficientZeroDegree));
    }

    const BinaryMul mul;
    long long integralDegree = (long long)(degree);
    map_int_LD returnedCoefficients = coefficientsSecond;

    if (integralDegree % 2 != 0)
    {
        returnedCoefficients.begin()->second--;
        return mul.getValue(polinomFirst, this->getValue(polinomFirst, *(new Polinom(returnedCoefficients))));
    }
    else
    {
        returnedCoefficients.begin()->second /= 2;
        const Node& returnedPolinom = this->getValue(polinomFirst, *(new Polinom(returnedCoefficients)));
        return mul.getValue(returnedPolinom, returnedPolinom);
    }
}
int BinaryPow::getNumArguments() const
{
    return 2;
}
void BinaryPow::print(ostream& os) const
{
    os << "Binary_Pow ";
}


