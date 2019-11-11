#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <utility>
#include <algorithm>
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

class UnaryPlus;  // : public NodeOneArgument
class UnaryMinus; // : public NodeOneArgument

class BinaryAdd; // : public NodeTwoArguments
class BinarySub; // : public NodeTwoArguments
class BinaryMul; // : public NodeTwoArguments
class BinaryDiv; // : public NodeTwoArguments
class BinaryPow; // : public NodeTwoArguments

typedef std::list < std::reference_wrapper < const Node > > list_node;
typedef std::map < int, long double > map_int_LD;

#endif // DEF_H_INCLUDED
