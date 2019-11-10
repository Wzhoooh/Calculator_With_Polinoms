#ifndef POLINOM_H_INCLUDED
#define POLINOM_H_INCLUDED

#include "../Node/Node.h"

#include <map>
#include <utility>

using std::map;
using std::pair;

typedef map < int, long double > map_int_LD;

class Polinom: public NodeZeroArguments
{
private:
    map_int_LD coefficients; /// < degree, coefficient >

public:
    Polinom() = default;
    Polinom(const Polinom&);
    Polinom(const map_int_LD);
    int getNumArguments() const final;
    const Node& getValue() const final;
    const Polinom& operator = (const Polinom&);

    map_int_LD getCoefficients() const; /// copies coefficients
    void print(ostream& os) const;
};

#endif // POLINOM_H_INCLUDED
