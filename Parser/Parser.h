#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "../def/def.h"
#include "../Exceptions/Exceptions.h"
#include "../Node/Node.h"
#include "../Polinom/Polinom.h"
#include "../Operations/Operations.h"
#include "../Brackets/Brackets.h"

class Parser
{
private:
    list_node expression;
    std::string strExpression;

public:
    Parser() = delete;
    Parser(const std::string& inputStr);
    list_node getExression() const;
};

#endif // PARSER_H_INCLUDED
