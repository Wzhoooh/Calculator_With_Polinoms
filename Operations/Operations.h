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
    const Node* getValue(Node* Number);
    int getNumArguments() const;
};

class UnaryMinus: public unaryOperation
{
private:
    int numArguments{1};
public:
    UnaryMinus() = default;
    const Node* getValue(Node* Number);
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
    const Node* getValue(Node* NumberFirst, Node* NumberSecond);
    int getNumArguments() const;
};

class BinarySub: public BinaryOperation
{
private:
    int numArguments{2};
public:
    BinarySub() = default;
    const Node* getValue(Node* NumberFirst, Node* NumberSecond);
    int getNumArguments() const;
};

class BinaryMul: public BinaryOperation
{
private:
    int numArguments{2};
public:
    BinaryMul() = default;
    const Node* getValue(Node* NumberFirst, Node* NumberSecond);
    int getNumArguments() const;
};

class BinaryDiv: public BinaryOperation
{
private:
    int numArguments{2};
public:
    BinaryDiv() = default;
    const Node* getValue(Node* NumberFirst, Node* NumberSecond);
    int getNumArguments() const;
};

class BinaryPow: public BinaryOperation
{
private:
    int numArguments{2};
public:
    BinaryPow() = default;
    const Node* getValue(Node* NumberFirst, Node* NumberSecond);
    int getNumArguments() const;
};

#endif // OPERATIONS_H_INCLUDED




