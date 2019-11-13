#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include "../def/def.h"

class Node
{
public:
    static constexpr long double MAX_NUMBER = 1e99;
    static constexpr long double MAX_DEGREE = 1e10;
    static constexpr long double  PRECISION = 1e-20;
    static constexpr int MAX_PRIORITY = 100;

    virtual int getNumArguments() const = 0;
    virtual int getPriority() const = 0;
    virtual void print(std::ostream& os) const = 0;
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
