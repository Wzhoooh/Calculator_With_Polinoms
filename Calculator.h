#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include "def/def.h"
#include "Exceptions/Exceptions.h"
#include "Node/Node.h"
#include "Polinom/Polinom.h"
#include "Operations/Operations.h"
#include "Brackets/Brackets.h"
#include "Parser/Parser.h"

class Calculator
{
private:
    list_node straightNotation;
    list_node backNotation;

    void reverseToBackNotation() throw (Invalid_Order, std::bad_cast);

public:
    Calculator() = delete;
    Calculator(list_node expression); /// pulled by Parser
    const Node& getResult() throw(Invalid_Order);

    void print(std::ostream& os) const;
};




#endif // CALCULATOR_H_INCLUDED

