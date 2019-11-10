#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#define MAX_NUMBER 1e18
#define MAX_DEGREE 10000

#include <exception>
#include <typeinfo>
using std::exception;
using std::bad_cast;

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
    const char* what() const throw() { return "dividing by zero"; }
};

class Too_Big_Number: public exception
{
public:
    const char* what() const throw() { return "too big number"; }
};

class Too_Big_Degree_Of_X: public exception
{
public:
    const char* what() const throw() { return "too big degree"; }
};

class Invalid_Degree_Of_X: public exception
{
public:
    const char* what() const throw() { return "invalid X degree"; }
};

class X_In_Degree: public exception
{
public:
    const char* what() const throw() { return "X in degree"; }
};

class Div_By_X: public exception
{
public:
    const char* what() const throw() { return "dividing by X"; }
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
