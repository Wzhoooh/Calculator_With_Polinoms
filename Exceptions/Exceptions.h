#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

class Div_By_Null; /// a / 0
class Too_Big_Number; /// infinity
class Too_Big_Degree_X; /// X^infinity
class Invalid_Degree_Of_X; /// X^(not Z) || X^(-1)
class X_In_Degree; /// a^( f(X) )
class Div_By_X; /// a / X

#endif // EXCEPTIONS_H_INCLUDED
