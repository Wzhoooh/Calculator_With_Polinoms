#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "../Exceptions/Exceptions.h"
#include "../Node/Node.h"
#include "../Polinom/Polinom.h"
#include "../Operations/Operations.h"

#include <string>
#include <list>
#include <functional>

using std::string;
using std::list;
using std::reference_wrapper;
//using std::ref;

class Parser
{
private:
    list < reference_wrapper < const Node > > expression;
    string strExpression;

public:
    Parser() = delete;
    Parser(const string& inputStr) throw(/**/);
    list < reference_wrapper < const Node > > getExression() const;
};

#endif // PARSER_H_INCLUDED
