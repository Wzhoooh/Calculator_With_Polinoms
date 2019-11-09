#ifndef POLINOM_H_INCLUDED
#define POLINOM_H_INCLUDED

#include <vector>
using std::vector;

class Polinom: public NodeZeroArguments
{
private:
    vector < long double > coefficients;

public:
    Polinom() = default;
    Polinom(const Polinom&);
    Polinom(const vector < long double >);
    int getNumArguments() const;
    Node* getValue();

    vector < long double > getCoefficients() const; /// copies coefficients
};

#endif // POLINOM_H_INCLUDED
