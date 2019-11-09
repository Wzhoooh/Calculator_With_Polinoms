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
};

class UnaryMinus: public NodeOneArgument
{
private:
    const int numArguments{1};
public:
    UnaryMinus() = default;
    const Node& getValue(const Node& polinom) const final;
    int getNumArguments() const final;
};



class BinaryAdd: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinaryAdd() = default;
    const Node& getValue(const Node& polinomFirst, const Node& polinomSecond) const throw(Too_Big_Number, Too_Big_Degree_Of_X) final;
    int getNumArguments() const final;
};

class BinarySub: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinarySub() = default;
    const Node& getValue(const Node& polinomFirst, const Node& polinomSecond) const throw(Too_Big_Number, Too_Big_Degree_Of_X) final;
    int getNumArguments() const final;
};

class BinaryMul: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinaryMul() = default;
    const Node& getValue(const Node& polinomFirst, const Node& polinomSecond) const throw(Too_Big_Number, Too_Big_Degree_Of_X) final;
    int getNumArguments() const final;
};

class BinaryDiv: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinaryDiv() = default;
    const Node& getValue(const Node& polinomFirst, const Node& polinomSecond) const throw(Too_Big_Number, Too_Big_Degree_Of_X) final;
    int getNumArguments() const final;
};

class BinaryPow: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinaryPow() = default;
    const Node& getValue(const Node& polinomFirst, const Node& polinomSecond) const throw(Too_Big_Number, Too_Big_Degree_Of_X) final;
    int getNumArguments() const final;
};

#endif // OPERATIONS_H_INCLUDED




