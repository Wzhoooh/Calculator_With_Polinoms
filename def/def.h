#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED

#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <list>
#include <vector>
#include <functional>

#define MAX_NUMBER 1e18
#define MAX_DEGREE 10000
#define  PRECISION 1e-20

class Calculator;
class Parser;

class Node; /// interface
class NodeZeroArguments; /// interface
class   NodeOneArgument; /// interface
class  NodeTwoArguments; /// interface

class Polinom; // : public NodeZeroArguments

class UnaryPlus;  // : public unaryOperation
class UnaryMinus; // : public unaryOperation

class BinaryAdd; // : public BinaryOperation
class BinarySub; // : public BinaryOperation
class BinaryMul; // : public BinaryOperation
class BinaryDiv; // : public BinaryOperation
class BinaryPow; // : public BinaryOperation

typedef std::list < std::reference_wrapper < const Node > > list_node;
typedef std::map < int, long double > map_int_LD;

#endif // DEF_H_INCLUDED
