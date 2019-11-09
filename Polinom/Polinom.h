#ifndef POLINOM_H_INCLUDED
#define POLINOM_H_INCLUDED

#include "../Node/Node.h"

#include <map>
#include <utility>
using std::map;
using std::pair;

typedef map < int, long double > map_int_LD;
typedef map < int, long double >::iterator map_int_LD_it;

class Polinom: public NodeZeroArguments
{
private:
    map_int_LD coefficients; /// < degree, coefficient >

public:
    Polinom() = default;
    Polinom(const Polinom&);
    Polinom(const map_int_LD);
    int getNumArguments() final;
    Node* getValue() final;

    map_int_LD getCoefficients() const; /// copies coefficients
};

#endif // POLINOM_H_INCLUDED
