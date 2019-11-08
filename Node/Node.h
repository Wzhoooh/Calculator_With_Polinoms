#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <vector>
using std::vector;

class Node
{
public:
    virtual Node* getValue(); /// value of Polinom
    virtual Node* getValue(Node*); /// unary operation
    virtual Node* getValue(Node*, Node*); /// binary operation
    virtual int getNumArguments();
};


#endif // NODE_H_INCLUDED
