#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include <vector>
#include <list>

using std::vector;
using std::list;

class Calculator;
class Parser;

class Node; /// interface

class Polinom;

class UnaryOperation; // : public Calculator
class UnaryPlus;  // : public unaryOperation
class UnaryMinus; // : public unaryOperation

class BinaryOperation; // : public Calculator
class BinaryAdd; // : public BinaryOperation
class BinarySub; // : public BinaryOperation
class BinaryMul; // : public BinaryOperation
class BinaryDiv; // : public BinaryOperation
class BinaryPow; // : public BinaryOperation


class Node
{
public:
    virtual const Node* getValue() = 0; /// value of NumberX
    virtual const Node* getValue(Node*) = 0; /// unary operation
    virtual const Node* getValue(Node*, Node*) = 0; /// binary operation
    virtual int getNumArguments() = 0;
};

#include "Exceptions/Exceptions.h"
#include "Polinom/Polinom.h"
#include "Operations/Operations.h"
#include "Parser/Parser.h"

class Calculator
{
private:
    list < Node* > expression;

    void reverseToBackNotation();

public:
    Calculator() = delete;
    Calculator(list < Node* >& expression); /// pulled by Parser

    Node* getResult();
};




#endif // CALCULATOR_H_INCLUDED

