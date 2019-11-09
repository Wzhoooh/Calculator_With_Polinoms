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

///----------------------Binary_Operations----------------------///

Node* BinaryAdd::getValue(Node* polinomFirst, Node* polinomSecond)
{}
int BinaryAdd::getNumArguments()
{}

Node* BinarySub::getValue(Node* polinomFirst, Node* polinomSecond)
{}
int BinarySub::getNumArguments()
{}

Node* BinaryMul::getValue(Node* polinomFirst, Node* polinomSecond)
{
    Polinom*  pointerPolinomFirst = static_cast < Polinom* > (polinomFirst);
    Polinom* pointerPolinomSecond = static_cast < Polinom* > (polinomSecond);
    map_int_LD  coefficientsFirst =  pointerPolinomFirst->getCoefficients();
    map_int_LD coefficientsSecond = pointerPolinomSecond->getCoefficients();
    map_int_LD resultedCoefficients;

    for (map_int_LD_it itFirst; itFirst != coefficientsFirst.end(); itFirst++)
    {
        for (map_int_LD_it itSecond; itSecond != coefficientsFirst.end(); itSecond++)
        {
            int resultedDegree = itFirst->first + itFirst->first;
            if (resultedDegree > MAX_DEGREE)
                throw new Too_Big_Degree_Of_X;

            long double resultedCoefficient = itFirst->second + itFirst->second;
            if (resultedCoefficient > MAX_NUMBER)
                throw new Too_Big_Number;

            resultedCoefficients.insert({resultedDegree, resultedCoefficient});
        }
    }

    return (Node*)new Polinom(resultedCoefficients);
}
int BinaryMul::getNumArguments()
{
    return 2;
}

Node* BinaryDiv::getValue(Node* polinomFirst, Node* polinomSecond)
{}
int BinaryDiv::getNumArguments()
{}

Node* BinaryPow::getValue(Node* polinomFirst, Node* polinomSecond)
{}
int BinaryPow::getNumArguments()
{}


