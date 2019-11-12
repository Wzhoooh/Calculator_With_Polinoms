#ifndef BRACKETS_H_INCLUDED
#define BRACKETS_H_INCLUDED

#include "../Node/Node.h"

class Bracket: public Node
{
private:
    bool isOpen;

public:
    static constexpr int OP_BRACKET = 1;
    static constexpr int CL_BRACKET = 2;

    Bracket() = delete;
    Bracket(bool isOpen);
    int getNumArguments() const final;
    int getPriority() const final;
    void print(std::ostream& os) const;
};

#endif // BRACKETS_H_INCLUDED
