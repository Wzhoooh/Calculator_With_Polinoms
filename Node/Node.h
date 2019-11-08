#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <vector>
using std::vector;

class Node
{
public:
    virtual int getNumArguments() = 0;
};


class NodeZeroArguments
{
public:
    virtual Node* getValue() = 0; /// value of Polinom
};

class NodeOneArgument
{
public:
    virtual Node* getValue(Node*) = 0; /// unary operation
};

class NodeTwoArguments
{
public:
    virtual Node* getValue(Node*, Node*) = 0; /// binary operation
};


#endif // NODE_H_INCLUDED
