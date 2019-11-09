#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <iostream>
#include <vector>

using std::ostream;
using std::vector;

class Node
{
public:
    virtual int getNumArguments() const = 0;
    virtual void print(ostream& os) const = 0;
};


class NodeZeroArguments: public Node
{
public:
    virtual const Node& getValue() const = 0; /// value of Polinom
};

class NodeOneArgument: public Node
{
public:
    virtual const Node& getValue(const Node&) const = 0; /// unary operation
};

class NodeTwoArguments: public Node
{
public:
    virtual const Node& getValue(const Node&, const Node&) const = 0; /// binary operation
};


#endif // NODE_H_INCLUDED
