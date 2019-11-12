#include "Calculator.h"

Calculator::Calculator(list_node expression)
{
    this->straightNotation = expression;
    reverseToBackNotation();
}

void Calculator::reverseToBackNotation() throw (Invalid_Order, std::bad_cast)
{
    stack_node operationStack;

    for (list_node::iterator i = straightNotation.begin(); i != straightNotation.end(); i++)
    {
        const Node& element = *i;
        if (element.getNumArguments() == 0) /// it is Polinom
        {
            backNotation.push_back(element);
        }
        else if (element.getNumArguments() == 1 || element.getNumArguments() == 2) /// operation
        {
            while (operationStack.size() > 0 && ((const Node&)operationStack.top()).getPriority() >= element.getPriority())
            {
                backNotation.push_back(operationStack.top());
                operationStack.pop();
            }
            operationStack.push(element);
        }
        else if (element.getNumArguments() > 0)
            throw Invalid_Operation();

        if (element.getPriority() == Bracket::OP_BRACKET) /// opened bracket
        {
            operationStack.push(element);
        }
        else if (element.getPriority() == Bracket::CL_BRACKET) /// closed bracket
        {
            while (operationStack.size() > 0 && ((const Node&)operationStack.top()).getPriority() != Bracket::OP_BRACKET)
            {
                backNotation.push_back(operationStack.top());
                operationStack.pop();
            }
            if (operationStack.size() == 0)
                throw Invalid_Order();

            operationStack.pop();
        }

    }
    while (operationStack.size() > 0)
    {
        if (((const Node&)operationStack.top()).getPriority() == Bracket::OP_BRACKET)
            throw Invalid_Order();
        backNotation.push_back(operationStack.top());
        operationStack.pop();
    }
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

            const Node& polinom = resultedStack.top();
            resultedStack.pop();
            const Node& newPolinom = (dynamic_cast < const NodeOneArgument& > (element)).getValue(polinom);
            resultedStack.push(newPolinom);
        }
        else if (element.getNumArguments() == 2)
        {
            if (resultedStack.size() < 2)
                throw Invalid_Order();

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

void Calculator::print(std::ostream& os) const
{
    os << "Straight:" << std::endl;
    for (auto i : straightNotation)
    {
        ((const Node&)i).print(os);
        os << std::endl;
    }

    os << std::endl;

    os << "Back:" << std::endl;
    for (auto i : backNotation)
    {
        ((const Node&)i).print(os);
        os << std::endl;
    }
}
