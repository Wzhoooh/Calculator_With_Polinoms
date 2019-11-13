#include "Operations.h"

#include <iostream>
#include <cstdlib>

const Node& UnaryMinus::getValue(const Node& polinom) const
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
int UnaryMinus::getPriority() const
{
    return MAX_PRIORITY - 3;
}
void UnaryMinus::print(std::ostream& os) const
{
    os << ".-";
}

const Node& UnaryPlus::getValue(const Node& polinom) const
{
    return *(new Polinom(dynamic_cast < const Polinom& > (polinom)));
}
int UnaryPlus::getNumArguments() const
{
    return 1;
}
int UnaryPlus::getPriority() const
{
    return MAX_PRIORITY - 3;
}
void UnaryPlus::print(std::ostream& os) const
{
    os << ".+";
}

///----------------------Binary_Operations----------------------///

const Node& BinaryAdd::getValue(const Node& polinomFirst, const Node& polinomSecond) const
{
    const Polinom&  pointerPolinomFirst = dynamic_cast < const Polinom& > (polinomFirst);
    const Polinom& pointerPolinomSecond = dynamic_cast < const Polinom& > (polinomSecond);
    map_int_LD  coefficientsFirst =  pointerPolinomFirst.getCoefficients();
    map_int_LD coefficientsSecond = pointerPolinomSecond.getCoefficients();
    map_int_LD resultedCoefficients = coefficientsFirst;

    for (map_int_LD::iterator itSecond = coefficientsSecond.begin(); itSecond != coefficientsSecond.end(); itSecond++)
    {
        resultedCoefficients[itSecond->first] += itSecond->second;
    }

    return *(new Polinom(resultedCoefficients));
}
int BinaryAdd::getNumArguments() const
{
    return 2;
}
int BinaryAdd::getPriority() const
{
    return MAX_PRIORITY - 6;
}
void BinaryAdd::print(std::ostream& os) const
{
    os << "+";
}

const Node& BinarySub::getValue(const Node& polinomFirst, const Node& polinomSecond) const
{
    BinaryAdd add;
    UnaryMinus minus;
    return add.getValue(polinomFirst, minus.getValue(polinomSecond));
}
int BinarySub::getNumArguments() const
{
    return 2;
}
int BinarySub::getPriority() const
{
    return MAX_PRIORITY - 6;
}
void BinarySub::print(std::ostream& os) const
{
    os << "-";
}

const Node& BinaryMul::getValue(const Node& polinomFirst, const Node& polinomSecond) const
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
            if (fabs(resultedCoefficient) > MAX_NUMBER)
                throw Too_Big_Number();

            resultedCoefficients[resultedDegree] += resultedCoefficient;
        }
    }

    return *(new Polinom(resultedCoefficients));
}
int BinaryMul::getNumArguments() const
{
    return 2;
}
int BinaryMul::getPriority() const
{
    return MAX_PRIORITY - 5;
}
void BinaryMul::print(std::ostream& os) const
{
    os << "*";
}

const Node& BinaryDiv::getValue(const Node& polinomFirst, const Node& polinomSecond) const
{
    const Polinom&  pointerPolinomFirst = dynamic_cast < const Polinom& > (polinomFirst);
    const Polinom& pointerPolinomSecond = dynamic_cast < const Polinom& > (polinomSecond);
    map_int_LD  coefficientsFirst =  pointerPolinomFirst.getCoefficients();
    map_int_LD coefficientsSecond = pointerPolinomSecond.getCoefficients();
    map_int_LD resultedCoefficients = coefficientsFirst;

    if (coefficientsSecond.size() != 1 || coefficientsSecond.begin()->first != 0)
        throw Div_By_X();

    long double divider = coefficientsSecond.begin()->second;
    if (fabs(divider) < PRECISION) /// 1e-20
        throw Div_By_Zero();

    for (auto& i : resultedCoefficients)
        i.second /= divider;

    return *(new Polinom(resultedCoefficients));
}
int BinaryDiv::getNumArguments() const
{
    return 2;
}
int BinaryDiv::getPriority() const
{
    return MAX_PRIORITY - 5;
}
void BinaryDiv::print(std::ostream& os) const
{
    os << "/";
}

const Node& BinaryPow::getValue(const Node& polinomFirst, const Node& polinomSecond) const
{
    const Polinom&  pointerPolinomFirst = dynamic_cast < const Polinom& > (polinomFirst);
    const Polinom& pointerPolinomSecond = dynamic_cast < const Polinom& > (polinomSecond);
    map_int_LD  coefficientsFirst =  pointerPolinomFirst.getCoefficients();
    map_int_LD coefficientsSecond = pointerPolinomSecond.getCoefficients();

    if (coefficientsSecond.size() != 1 || coefficientsSecond.begin()->first != 0)
        throw X_In_Degree();

    long double degree = coefficientsSecond.begin()->second;

    if (degree == 0)
    {
        map_int_LD coefficientZeroDegree;
        coefficientZeroDegree.insert({0, 1});
        return *( new Polinom(coefficientZeroDegree));
    }

    if (fabs(degree) > MAX_DEGREE)
        throw Too_Big_Degree();

    if (coefficientsFirst.size() != 1 || coefficientsFirst.begin()->first != 0)
    {
        if ((long long)degree != degree || degree < 0)
            throw Invalid_Degree_Of_X();

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
    else
    {
        long double result = pow(coefficientsFirst.begin()->second, degree);
        map_int_LD newCoefficient;
        newCoefficient.insert({0, result});
        return *(new Polinom(newCoefficient));
    }
}
int BinaryPow::getNumArguments() const
{
    return 2;
}
int BinaryPow::getPriority() const
{
    return MAX_PRIORITY - 4;
}
void BinaryPow::print(std::ostream& os) const
{
    os << "^";
}


