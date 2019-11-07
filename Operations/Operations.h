#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

class UnaryOperation: public Node
{};

class UnaryPlus: public unaryOperation
{
private:
    int numArguments{1};

public:
    UnaryPlus() = default;
    Node getValue(Node* Number);
    int getNumArguments() const;
};

class UnaryMinus: public unaryOperation
{
private:
    int numArguments{1};
public:
    UnaryMinus() = default;
    Node getValue(Node* Number);
    int getNumArguments() const;
};



class BinaryOperation: public Node
{};

class BinaryAdd: public BinaryOperation
{
private:
    int numArguments{2};
public:
    BinaryAdd() = default;
    Node getValue(Node* NumberFirst, Node* NumberSecond);
    int getNumArguments() const;
};

class BinarySub: public BinaryOperation
{
private:
    int numArguments{2};
public:
    BinarySub() = default;
    Node getValue(Node* NumberFirst, Node* NumberSecond);
    int getNumArguments() const;
};

class BinaryMul: public BinaryOperation
{
private:
    int numArguments{2};
public:
    BinaryMul() = default;
    Node getValue(Node* NumberFirst, Node* NumberSecond);
    int getNumArguments() const;
};

class BinaryDiv: public BinaryOperation
{
private:
    int numArguments{2};
public:
    BinaryDiv() = default;
    Node getValue(Node* NumberFirst, Node* NumberSecond);
    int getNumArguments() const;
};

class BinaryPow: public BinaryOperation
{
private:
    int numArguments{2};
public:
    BinaryPow() = default;
    Node getValue(Node* NumberFirst, Node* NumberSecond);
    int getNumArguments() const;
};

#endif // OPERATIONS_H_INCLUDED




