#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <utility>
#include <algorithm>
#include <iterator>
#include <functional>

class Calculator;
class Parser;

class Node; /// interface
class NodeZeroArguments; /// : public Node
class   NodeOneArgument; /// : public Node
class  NodeTwoArguments; /// : public Node

class Polinom; // : public NodeZeroArguments

class UnaryPlus;  // : public NodeOneArgument
class UnaryMinus; // : public NodeOneArgument

class BinaryAdd; // : public NodeTwoArguments
class BinarySub; // : public NodeTwoArguments
class BinaryMul; // : public NodeTwoArguments
class BinaryDiv; // : public NodeTwoArguments
class BinaryPow; // : public NodeTwoArguments

class Bracket; /// : public Node

typedef std::list < std::reference_wrapper < const Node > > list_node;
typedef std::stack < std::reference_wrapper < const Node > > stack_node;
typedef std::map < int, long double > map_int_LD;

#endif // DEF_H_INCLUDED
