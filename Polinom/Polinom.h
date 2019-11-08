#ifndef POLINOM_H_INCLUDED
#define POLINOM_H_INCLUDED

#include <vector>
using std::vector;

typedef vector < long double > vect_l_d;


class Polinom: public Node
{
private:
    int numArguments{0};
    vect_l_d coefficients;

public:
    Polinom();
    Polinom(const Polinom&);
    Polinom(const vect_l_d&);
    int getNumArguments() const;
    const Node* getValue();

    vect_l_d getCoefficients() const; /// copies coefficients
};

#endif // POLINOM_H_INCLUDED
