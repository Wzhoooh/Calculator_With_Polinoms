#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <string>
#include <list>

using std::string;
using std::list;

class Parser
{
private:
    list < Node* > expression;
    string strExpression;

public:
    Parser() = delete;
    Parser(const string& inputStr);
    list < Node* > getExression() const;
};

#endif // PARSER_H_INCLUDED
