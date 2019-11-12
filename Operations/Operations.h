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
    const Node& getValue(const Node& polinom) const final;
    int getNumArguments() const final;
    int getPriority() const final;
    void print(std::ostream& os) const;
};

class UnaryMinus: public NodeOneArgument
{
private:
    const int numArguments{1};
public:
    UnaryMinus() = default;
    const Node& getValue(const Node& polinom) const final;
    int getNumArguments() const final;
    int getPriority() const final;
    void print(std::ostream& os) const;
};



class BinaryAdd: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinaryAdd() = default;
    const Node& getValue(const Node& polinomFirst, const Node& polinomSecond) const final;
    int getNumArguments() const final;
    int getPriority() const final;
    void print(std::ostream& os) const;
};

class BinarySub: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinarySub() = default;
    const Node& getValue(const Node& polinomFirst, const Node& polinomSecond) const final;
    int getNumArguments() const final;
    int getPriority() const final;
    void print(std::ostream& os) const;
};

class BinaryMul: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinaryMul() = default;
    const Node& getValue(const Node& polinomFirst, const Node& polinomSecond) const final;
    int getNumArguments() const final;
    int getPriority() const final;
    void print(std::ostream& os) const;
};

class BinaryDiv: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinaryDiv() = default;
    const Node& getValue(const Node& polinomFirst, const Node& polinomSecond) const final;
    int getNumArguments() const final;
    int getPriority() const final;
    void print(std::ostream& os) const;
};

class BinaryPow: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinaryPow() = default;
    const Node& getValue(const Node& polinomFirst, const Node& polinomSecond) const final;
    int getNumArguments() const final;
    int getPriority() const final;
    void print(std::ostream& os) const;
};

#endif // OPERATIONS_H_INCLUDED




