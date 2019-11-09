#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include <vector>
#include <list>

using std::vector;
using std::list;

class Calculator;
class Parser;

class Node; /// interface
class NodeZeroArguments; /// interface
class   NodeOneArgument; /// interface
class  NodeTwoArguments; /// interface

class Polinom; // : public Node

class UnaryPlus;  // : public unaryOperation
class UnaryMinus; // : public unaryOperation

class BinaryAdd; // : public BinaryOperation
class BinarySub; // : public BinaryOperation
class BinaryMul; // : public BinaryOperation
class BinaryDiv; // : public BinaryOperation
class BinaryPow; // : public BinaryOperation


#include "Node/Node.h"
#include "Exceptions/Exceptions.h"
#include "Polinom/Polinom.h"
#include "Operations/Operations.h"
#include "Parser/Parser.h"

class Calculator
{
private:
    list < Node > expression;

    void reverseToBackNotation();

public:
    Calculator() = delete;
    Calculator(list < Node >& expression); /// pulled by Parser

    Node& getResult();
};




#endif // CALCULATOR_H_INCLUDED

