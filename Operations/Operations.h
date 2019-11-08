#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

class UnaryPlus: public Node
{
private:
    const int numArguments{1};

public:
    UnaryPlus() = default;
    Node* getValue(Node* Number);
    int getNumArguments() const;
};

class UnaryMinus: public Node
{
private:
    const int numArguments{1};
public:
    UnaryMinus() = default;
    Node* getValue(Node* Number);
    int getNumArguments() const;
};



class BinaryAdd: public Node
{
private:
    const int numArguments{2};
public:
    BinaryAdd() = default;
    Node* getValue(Node* NumberFirst, Node* NumberSecond);
    int getNumArguments() const;
};

class BinarySub: public Node
{
private:
    const int numArguments{2};
public:
    BinarySub() = default;
    Node* getValue(Node* NumberFirst, Node* NumberSecond);
    int getNumArguments() const;
};

class BinaryMul: public Node
{
private:
    const int numArguments{2};
public:
    BinaryMul() = default;
    Node* getValue(Node* NumberFirst, Node* NumberSecond);
    int getNumArguments() const;
};

class BinaryDiv: public Node
{
private:
    const int numArguments{2};
public:
    BinaryDiv() = default;
    Node* getValue(Node* NumberFirst, Node* NumberSecond);
    int getNumArguments() const;
};

class BinaryPow: public Node
{
private:
    const int numArguments{2};
public:
    BinaryPow() = default;
    Node* getValue(Node* NumberFirst, Node* NumberSecond);
    int getNumArguments() const;
};

#endif // OPERATIONS_H_INCLUDED




