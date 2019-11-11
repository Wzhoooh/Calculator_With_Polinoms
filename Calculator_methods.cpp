#include "Calculator.h"

Calculator::Calculator(list_node expression)
{
    this->straightNotation = expression;
    this->backNotation = this->straightNotation;
}

const Node& Calculator::getResult() throw(Invalid_Order)
{
    for (list_node::iterator i = backNotation.begin(); i != backNotation.end(); i++)
    {
        const Node& element = *i;

        if (element.getNumArguments() == 1) /// we are taking one Node before element
        {
            const Node& operation = (const Node&)(*i);
            list_node::iterator polinomIt = i;
            list_node::iterator operationIt = i;
            advance(polinomIt, -1);
            if (polinomIt == backNotation.end())
                throw Invalid_Order();

            const Node& polinom = (const Node&)(*polinomIt);
            const Node& result = (dynamic_cast < const NodeOneArgument& > (operation)).getValue(polinom);
            advance(i, 1);
            backNotation.erase(polinomIt);
            backNotation.erase(operationIt);
            backNotation.insert(i, result);
        }
        if (element.getNumArguments() == 2) /// we are taking two Nodes before element
        {
            const Node& operation = (const Node&)(*i);
            list_node::iterator  polinomFirstIt = i;
            list_node::iterator polinomSecondIt = i;
            list_node::iterator operationIt = i;
            advance( polinomFirstIt, -2);
            advance(polinomSecondIt, -1);
            if (polinomFirstIt == backNotation.end() || polinomSecondIt == backNotation.end())
                throw Invalid_Order();

            const Node& polinomFirst = (const Node&)(*polinomFirstIt);
            const Node& polinomSecond = (const Node&)(*polinomSecondIt);
            const Node& result = (dynamic_cast < const NodeTwoArguments& > (operation)).getValue(polinomFirst, polinomSecond);
            advance(i, 1);
            backNotation.erase(polinomFirstIt);
            backNotation.erase(polinomSecondIt);
            backNotation.erase(operationIt);
            backNotation.insert(i, result);
        }
    }
    if (backNotation.size() != 1)
        throw Invalid_Order();

    return (const Node&)(*backNotation.begin());
}
