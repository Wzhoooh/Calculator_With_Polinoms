#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#include "Node/Node.h"
#include "Exceptions/Exceptions.h"
#include "Polinom/Polinom.h"
#include "Operations/Operations.h"
#include "Parser/Parser.h"

class Calculator
{
private:
    list_node straightNotation;
    list_node backNotation;

    void reverseToBackNotation();

public:
    Calculator() = delete;
    Calculator(list_node expression); /// pulled by Parser
    const Node& getResult();
};




#endif // CALCULATOR_H_INCLUDED

