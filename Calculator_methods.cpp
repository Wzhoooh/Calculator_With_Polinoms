#include "Calculator.h"

Calculator::Calculator(list_node expression)
{
    this->backNotation = expression;
    //this->straightNotation = nullptr;
}

const Node& Calculator::getResult() throw(Invalid_Order)
{
    stack_node resultedStack;

    for (list_node::iterator i = backNotation.begin(); i != backNotation.end(); i++)
    {
        const Node& element = *i;
        if (element.getNumArguments() == 0) /// Polinom
            resultedStack.push(element);

        else if (element.getNumArguments() == 1)
        {
            if (resultedStack.size() < 1)
                throw Invalid_Order();

            const Node& operation = element;
            const Node& polinom = resultedStack.top();
            resultedStack.pop();
            const Node& newPolinom = (dynamic_cast < const NodeOneArgument& > (element)).getValue(polinom);
            resultedStack.push(newPolinom);
        }
        else if (element.getNumArguments() == 2)
        {
            if (resultedStack.size() < 2)
                throw Invalid_Order();

            const Node& operation = element;
            const Node& polinomSecond = resultedStack.top();
            resultedStack.pop();
            const Node& polinomFirst = resultedStack.top();
            resultedStack.pop();
            const Node& newPolinom = (dynamic_cast < const NodeTwoArguments& > (element)).getValue(polinomFirst, polinomSecond);
            resultedStack.push(newPolinom);
        }
        else
            throw Invalid_Order();
    }
    if (resultedStack.size() != 1)
        throw Invalid_Order();

    return resultedStack.top();
}
