#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include <vector>
#include <list>

using std::vector;
using std::list;

class Calculator;
class Parser;

class Node; /// interface

class NumberX;

class UnaryOperation; // : public Calculator
class UnaryPlus;  // : public unaryOperation
class UnaryMinus; // : public unaryOperation

class BinaryOperation; // : public Calculator
class BinaryAdd; // : public BinaryOperation
class BinarySub; // : public BinaryOperation
class BinaryMul; // : public BinaryOperation
class BinaryDiv; // : public BinaryOperation
class BinaryPow; // : public BinaryOperation

typedef list < Node* > list_node;

#include "Exceptions/Exceptions.h"
#include "Operations/Operations.h"
#include "Parser/Parser.h"

class Calculator
{
private:
    list_node expression;

public:
    Calculator() = delete;
    Calculator(list_node& expression);

    void reverseToBackNotation();
    Node getResult();
};

class Node
{
public:
    virtual vect_l_d getValue() = 0; /// value of NumberX
    virtual Node getValue(Node*) = 0; /// unary operation
    virtual Node getValue(Node*, Node*) = 0; /// binary operation
    virtual int getNumArguments() = 0;
};


#endif // CALCULATOR_H_INCLUDED

