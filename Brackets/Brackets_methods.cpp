#include "Brackets.h"

Bracket::Bracket(bool isOpen): isOpen(isOpen)
{}

int Bracket::getNumArguments() const
{
    return -1;
}
int Bracket::getPriority() const
{
    return isOpen ? OP_BRACKET : CL_BRACKET;
}

void Bracket::print(std::ostream& os) const
{
    os << (isOpen ? "(" : ")");
}
