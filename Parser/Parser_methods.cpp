#include "Parser.h"

Parser::Parser(const string& inputStr) throw(/**/)
{
    const Node& n = Polinom();
    expression.push_back(n);


}

list < reference_wrapper < const Node > > Parser::getExression() const
{

}
