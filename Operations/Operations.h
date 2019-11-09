#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

#include "../Polinom/Polinom.h"
#include "../Exceptions/Exceptions.h"

class UnaryPlus: public NodeOneArgument
{
private:
    const int numArguments{1};

public:
    UnaryPlus() = default;
    Node* getValue(Node* polinom) final;
    int getNumArguments() final;
};

class UnaryMinus: public NodeOneArgument
{
private:
    const int numArguments{1};
public:
    UnaryMinus() = default;
    Node* getValue(Node* polinom) final;
    int getNumArguments() final;
};



class BinaryAdd: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinaryAdd() = default;
    Node* getValue(Node* polinomFirst, Node* polinomSecond) final;
    int getNumArguments() final;
};

class BinarySub: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinarySub() = default;
    Node* getValue(Node* polinomFirst, Node* polinomSecond) final;
    int getNumArguments() final;
};

class BinaryMul: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinaryMul() = default;
    Node* getValue(Node* polinomFirst, Node* polinomSecond) final;
    int getNumArguments() final;
};

class BinaryDiv: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinaryDiv() = default;
    Node* getValue(Node* polinomFirst, Node* polinomSecond) final;
    int getNumArguments() final;
};

class BinaryPow: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinaryPow() = default;
    Node* getValue(Node* polinomFirst, Node* polinomSecond) final;
    int getNumArguments() final;
};

#endif // OPERATIONS_H_INCLUDED




