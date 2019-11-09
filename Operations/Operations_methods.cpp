#include "Operations.h"

#include <iostream>

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

///----------------------Binary_Operations----------------------///

Node* BinaryAdd::getValue(Node* polinomFirst, Node* polinomSecond) throw(Too_Big_Number, Too_Big_Degree_Of_X)
{
    Polinom*  pointerPolinomFirst = static_cast < Polinom* > (polinomFirst);
    Polinom* pointerPolinomSecond = static_cast < Polinom* > (polinomSecond);
    map_int_LD  coefficientsFirst =  pointerPolinomFirst->getCoefficients();
    map_int_LD coefficientsSecond = pointerPolinomSecond->getCoefficients();
    map_int_LD resultedCoefficients = coefficientsFirst;

    for (map_int_LD_it itSecond = coefficientsSecond.begin(); itSecond != coefficientsSecond.end(); itSecond++)
        resultedCoefficients[itSecond->first] += itSecond->second;

    return (Node*)new Polinom(resultedCoefficients);
}
int BinaryAdd::getNumArguments()
{}

Node* BinarySub::getValue(Node* polinomFirst, Node* polinomSecond) throw(Too_Big_Number, Too_Big_Degree_Of_X)
{}
int BinarySub::getNumArguments()
{}

Node* BinaryMul::getValue(Node* polinomFirst, Node* polinomSecond) throw(Too_Big_Number, Too_Big_Degree_Of_X)
{
    Polinom*  pointerPolinomFirst = static_cast < Polinom* > (polinomFirst);
    Polinom* pointerPolinomSecond = static_cast < Polinom* > (polinomSecond);
    map_int_LD  coefficientsFirst =  pointerPolinomFirst->getCoefficients();
    map_int_LD coefficientsSecond = pointerPolinomSecond->getCoefficients();
    map_int_LD resultedCoefficients;

    for (map_int_LD_it itFirst = coefficientsFirst.begin(); itFirst != coefficientsFirst.end(); itFirst++)
    {
        for (map_int_LD_it itSecond = coefficientsSecond.begin(); itSecond != coefficientsSecond.end(); itSecond++)
        {
            int resultedDegree = itFirst->first + itSecond->first;
            if (resultedDegree > MAX_DEGREE)
                throw new Too_Big_Degree_Of_X;

            long double resultedCoefficient = itFirst->second * itSecond->second;
            if (resultedCoefficient > MAX_NUMBER)
                throw new Too_Big_Number;

            resultedCoefficients[resultedDegree] += resultedCoefficient;
        }
    }

    return (Node*)new Polinom(resultedCoefficients);
}
int BinaryMul::getNumArguments()
{
    return 2;
}

Node* BinaryDiv::getValue(Node* polinomFirst, Node* polinomSecond) throw(Too_Big_Number, Too_Big_Degree_Of_X)
{}
int BinaryDiv::getNumArguments()
{}

Node* BinaryPow::getValue(Node* polinomFirst, Node* polinomSecond) throw(Too_Big_Number, Too_Big_Degree_Of_X)
{}
int BinaryPow::getNumArguments()
{}


