#ifndef POLINOM_H_INCLUDED
#define POLINOM_H_INCLUDED

#include "../Node/Node.h"

class Polinom: public NodeZeroArguments
{
private:
    map_int_LD coefficients; /// < degree, coefficient >

public:
    Polinom() = default;
    Polinom(const Polinom&);
    Polinom(const map_int_LD);
    const Node& getValue() const final;
    int getNumArguments() const final;
    int getPriority() const final;
    const Polinom& operator = (const Polinom&);

    map_int_LD getCoefficients() const; /// copies coefficients
    void print(std::ostream& os) const;
};

#endif // POLINOM_H_INCLUDED
