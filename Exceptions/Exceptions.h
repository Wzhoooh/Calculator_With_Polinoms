#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <exception>
#include <typeinfo>

using std::exception;
using std::bad_cast;

class           Div_By_Zero; /// a / 0
class        Too_Big_Number; /// infinity
class        Too_Big_Degree; /// X^infinity
class   Invalid_Degree_Of_X; /// X^(not Z) || X^(-1)
class           X_In_Degree; /// a ^ ( f(X) )
class              Div_By_X; /// a / ( f(X) )

class Invalid_Order;
class Invalid_Cast;
class Invalid_Operation;
class Invalid_Symbol;


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

class Too_Big_Degree: public exception
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

class Invalid_Operation: public exception
{
public:
    const char* what() const throw() { return "invalid cast"; }
};

class Invalid_Symbol: public exception
{
public:
    const char* what() const throw() { return "invalid symbol"; }
};

#endif // EXCEPTIONS_H_INCLUDED
