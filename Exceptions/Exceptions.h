#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <exception>
using std::exception;

class           Div_By_Zero; /// a / 0
class        Too_Big_Number; /// infinity
class   Too_Big_Degree_Of_X; /// X^infinity
class   Invalid_Degree_Of_X; /// X^(not Z) || X^(-1)
class           X_In_Degree; /// a ^ ( f(X) )
class              Div_By_X; /// a / ( f(X) )

class Invalid_Order;
class Invalid_Cast;


class Div_By_Zero: public exception
{
public:
    const char* what() const throw() { return ""; }
};

class Too_Big_Number: public exception
{
public:
    const char* what() const throw() { return ""; }
};

class Too_Big_Degree_Of_X: public exception
{
public:
    const char* what() const throw() { return ""; }
};

class Invalid_Degree_Of_X: public exception
{
public:
    const char* what() const throw() { return ""; }
};

class X_In_Degree: public exception
{
public:
    const char* what() const throw() { return ""; }
};

class Div_By_X: public exception
{
public:
    const char* what() const throw() { return ""; }
};

class Invalid_Order: public exception
{
public:
    const char* what() const throw() { return "invalid order"; }
};

class Invalid_Cast: public exception
{
public:
    const char* what() const throw() { return "invalid cast"; }
};


#endif // EXCEPTIONS_H_INCLUDED
