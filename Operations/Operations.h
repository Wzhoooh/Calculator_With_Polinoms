#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

class UnaryOperation: public Node
{};

class UnaryPlus: public UnaryOperation
{
private:
    const int numArguments{1};

public:
    UnaryPlus() = default;
    vector < long double > getValue(Node* Number);
    int getNumArguments() const;
};

class UnaryMinus: public UnaryOperation
{
private:
    const int numArguments{1};
public:
    UnaryMinus() = default;
    vector < long double > getValue(Node* Number);
    int getNumArguments() const;
};



class BinaryOperation: public Node
{};

class BinaryAdd: public BinaryOperation
{
private:
    const int numArguments{2};
public:
    BinaryAdd() = default;
    vector < long double > getValue(Node* NumberFirst, Node* NumberSecond);
    int getNumArguments() const;
};

class BinarySub: public BinaryOperation
{
private:
    const int numArguments{2};
public:
    BinarySub() = default;
    vector < long double > getValue(Node* NumberFirst, Node* NumberSecond);
    int getNumArguments() const;
};

class BinaryMul: public BinaryOperation
{
private:
    const int numArguments{2};
public:
    BinaryMul() = default;
    vector < long double > getValue(Node* NumberFirst, Node* NumberSecond);
    int getNumArguments() const;
};

class BinaryDiv: public BinaryOperation
{
private:
    const int numArguments{2};
public:
    BinaryDiv() = default;
    vector < long double > getValue(Node* NumberFirst, Node* NumberSecond);
    int getNumArguments() const;
};

class BinaryPow: public BinaryOperation
{
private:
    const int numArguments{2};
public:
    BinaryPow() = default;
    vector < long double > getValue(Node* NumberFirst, Node* NumberSecond);
    int getNumArguments() const;
};

#endif // OPERATIONS_H_INCLUDED




