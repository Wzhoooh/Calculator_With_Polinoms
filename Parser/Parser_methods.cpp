#include "Parser.h"

Parser::Parser(const std::string& inputStr)
{
    for (int i = 0; i < inputStr.size(); i++)
    {
        char element = inputStr[i];

        if (element == 'x')
        {
            expression.push_back( *(new Polinom(map_int_LD { {1, 1} } )) );
        }
        else if (element >= '0' && element <= '9' || element == '.')
        {
            std::string tokenNumber;
            for ( ;i < inputStr.size() && (inputStr[i] >= '0' && inputStr[i] <= '9' || inputStr[i] == '.'); i++ )
                tokenNumber += inputStr[i];

            i--;
            std::stringstream ss;
            ss << tokenNumber;
            long double number;
            ss >> number;
            expression.push_back( *(new Polinom(map_int_LD{ {0, number} } )) );
        }
        else if (element == '+')
        {
            if (expression.size() == 0 || ((const Node&)*expression.rbegin()).getPriority() == Bracket::OP_BRACKET)
                expression.push_back( *(new UnaryPlus()) );
            else
                expression.push_back( *(new BinaryAdd()) );
        }
        else if (element == '-')
        {
            if (expression.size() == 0 || ((const Node&)*expression.rbegin()).getPriority() == Bracket::OP_BRACKET)
                expression.push_back( *(new UnaryMinus()) );
            else
                expression.push_back( *(new BinarySub()) );
        }
        else if (element == '*')
        {
            expression.push_back( *(new BinaryMul()) );
        }
        else if (element == '/')
        {
            expression.push_back( *(new BinaryDiv()) );
        }
        else if (element == '^')
        {
            expression.push_back( *(new BinaryPow()) );
        }
        else if (element == '(')
        {
            expression.push_back( *(new Bracket(true)) );
        }
        else if (element == ')')
        {
            expression.push_back( *(new Bracket(false)) );
        }
        else if (element == ' ' || (element == '=' && i == inputStr.size()-1))
        {
            continue;
        }

        else
            throw Invalid_Symbol(element);
    }
}

list_node Parser::getExression() const
{
    return expression;
}
