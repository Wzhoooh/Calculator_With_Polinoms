#ifndef POLINOM_H_INCLUDED
#define POLINOM_H_INCLUDED

#include <vector>
using std::vector;

class Polinom: public Node
{
private:
    int numArguments{0};
    vector < long double > coefficients;

public:
    Polinom();
    Polinom(const Polinom&);
    Polinom(const vector < long double >&);
    int getNumArguments() const;
    vector < long double > getValue();

    //vector < long double > getCoefficients() const; /// copies coefficients
};

#endif // POLINOM_H_INCLUDED
