#include "../Node/Node.h"
#include "../Polinom/Polinom.h"
#include "../Exceptions/Exceptions.h"
#include "Operations.h"

Node* UnaryMinus::getValue(Node* polinom)
{
    Polinom p;
    Node* p = new Polinom(vector < long double >());
    NodeZeroArguments* nZero = static_cast < NodeZeroArguments* > (p);

    NodeZeroArguments* pointerZeroArguments = static_cast < NodeZeroArguments* > (polinom);
    Polinom* pointerPolinom = static_cast < Polinom* > (pointerZeroArguments);
    vector < double > coefficients = pointerPolinom->getCoefficients();
}
int UnaryMinus::getNumArguments() const
{

}
