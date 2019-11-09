#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

class UnaryPlus: public NodeOneArgument
{
private:
    const int numArguments{1};

public:
    UnaryPlus() = default;
    Node* getValue(Node* polinom);
    int getNumArguments() const;
};

class UnaryMinus: public NodeOneArgument
{
private:
    const int numArguments{1};
public:
    UnaryMinus() = default;
    Node* getValue(Node* polinom);
    int getNumArguments() const;
};



class BinaryAdd: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinaryAdd() = default;
    Node* getValue(Node* polinomFirst, Node* polinomSecond);
    int getNumArguments() const;
};

class BinarySub: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinarySub() = default;
    Node* getValue(Node* polinomFirst, Node* polinomSecond);
    int getNumArguments() const;
};

class BinaryMul: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinaryMul() = default;
    Node* getValue(Node* polinomFirst, Node* polinomSecond);
    int getNumArguments() const;
};

class BinaryDiv: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinaryDiv() = default;
    Node* getValue(Node* polinomFirst, Node* polinomSecond);
    int getNumArguments() const;
};

class BinaryPow: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinaryPow() = default;
    Node* getValue(Node* polinomFirst, Node* polinomSecond);
    int getNumArguments() const;
};

#endif // OPERATIONS_H_INCLUDED




