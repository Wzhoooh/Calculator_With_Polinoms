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

    for (map_int_LD_it itSecond = coefficientsSecond.begin(); itSecond != coefficientsSecond.end(); itSecond++)
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

    for (map_int_LD_it itFirst = coefficientsFirst.begin(); itFirst != coefficientsFirst.end(); itFirst++)
    {
        for (map_int_LD_it itSecond = coefficientsSecond.begin(); itSecond != coefficientsSecond.end(); itSecond++)
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
    if (divider == 0)
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
    map_int_LD resultedCoefficients = coefficientsFirst;

    long double degree = coefficientsSecond.begin()->second;
std::cout << "degree: " << degree << std::endl;
    if (coefficientsSecond.size() != 1 || coefficientsSecond.begin()->first != 0)
        throw X_In_Degree();

    if (degree > MAX_DEGREE)
        throw Too_Big_Degree();

    if ((coefficientsFirst.size() != 1 && (long long)degree != degree) || degree < 0)
        throw Invalid_Degree_Of_X();

    if (degree == 0)
    {
        resultedCoefficients.insert({0, 1});
        return *(new Polinom(resultedCoefficients));
    }

const Node& p = pointerPolinomFirst.getValue();
(dynamic_cast < const Polinom& > (p)).print(std::cout);
std::cout << std::endl;

    //Node& resultedPolinom = const_cast < Node& > ((dynamic_cast < const Polinom& > (polinomFirst)).getValue());
    Node& resultedPolinom = const_cast < Node& > (pointerPolinomFirst.getValue());
    const BinaryMul& mul = BinaryMul();
    while (degree > 0)
    {
        (dynamic_cast < const Polinom& > (resultedPolinom)).print(std::cout);
        std::cout << std::endl;
        resultedPolinom = mul.getValue(resultedPolinom, polinomFirst);
        degree--;
    }

(dynamic_cast < const Polinom& > (resultedPolinom)).print(std::cout);
std::cout << "---------";

    return (dynamic_cast < const Polinom& > (resultedPolinom)).getValue();
}
int BinaryPow::getNumArguments() const
{
    return 2;
}
void BinaryPow::print(ostream& os) const
{
    os << "Binary_Pow ";
}


