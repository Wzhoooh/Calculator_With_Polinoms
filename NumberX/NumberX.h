#ifndef COEFFICIENTS_H_INCLUDED
#define COEFFICIENTS_H_INCLUDED

#include <vector>
using std::vector;

typedef vector < long double > vect_l_d;


class NumberX: public Node
{
private:
    int numArguments{0};
    vect_l_d coefficients;

public:
    NumberX();
    NumberX(const NumberX&);
    NumberX(const vect_l_d&);
    int getNumArguments() const;
    const Node* getValue();

    vect_l_d getCopy() const; /// copies coefficients
};

#endif // COEFFICIENTS_H_INCLUDED
