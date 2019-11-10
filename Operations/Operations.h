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
    const Node& getValue(const Node& polinom) const throw(bad_cast) final;
    int getNumArguments() const final;
    void print(ostream& os) const;
};

class UnaryMinus: public NodeOneArgument
{
private:
    const int numArguments{1};
public:
    UnaryMinus() = default;
    const Node& getValue(const Node& polinom) const throw(bad_cast) final;
    int getNumArguments() const final;
    void print(ostream& os) const;
};



class BinaryAdd: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinaryAdd() = default;
    const Node& getValue(const Node& polinomFirst, const Node& polinomSecond) const throw(Too_Big_Number, bad_cast) final;
    int getNumArguments() const final;
    void print(ostream& os) const;
};

class BinarySub: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinarySub() = default;
    const Node& getValue(const Node& polinomFirst, const Node& polinomSecond) const throw(Too_Big_Number, bad_cast) final;
    int getNumArguments() const final;
    void print(ostream& os) const;
};

class BinaryMul: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinaryMul() = default;
    const Node& getValue(const Node& polinomFirst, const Node& polinomSecond) const throw(Too_Big_Number, Too_Big_Degree, bad_cast) final;
    int getNumArguments() const final;
    void print(ostream& os) const;
};

class BinaryDiv: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinaryDiv() = default;
    const Node& getValue(const Node& polinomFirst, const Node& polinomSecond) const throw(Too_Big_Number, Div_By_X, Div_By_Zero, bad_cast) final;
    int getNumArguments() const final;
    void print(ostream& os) const;
};

class BinaryPow: public NodeTwoArguments
{
private:
    const int numArguments{2};
public:
    BinaryPow() = default;
    const Node& getValue(const Node& polinomFirst, const Node& polinomSecond) const throw(Too_Big_Number, Too_Big_Degree, X_In_Degree, Invalid_Degree_Of_X, bad_cast) final;
    int getNumArguments() const final;
    void print(ostream& os) const;
};

#endif // OPERATIONS_H_INCLUDED




