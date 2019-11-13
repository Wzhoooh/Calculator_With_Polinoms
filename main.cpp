#include <iostream>
#include <climits>
#include <set>
//#include <windows.h>
#include <conio.h>
#include "Calculator.h"

using namespace std;

int main()
{
    unsigned char byteFirst  = 0;
    unsigned char byteSecond = 0;
    string inputStr;
    string result;
    int bracketsState = 0;
    char lastSymbol = 0;
    bool enterPressed = false;
    set < char > rightSymbols{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    '+', '-', '*', '/', '^', '.', '=', '(', ')', 'x'};

    set < char > operations{'+', '-', '*', '/', '^'};

    for (;;)
    {
        if (inputStr.size() > 0)
            lastSymbol = inputStr[inputStr.size()-1];
        else
            lastSymbol = 0;

        byteFirst  = 0;
        byteSecond = 0;
        system("cls");
        cout << inputStr << endl;
        cout << "-----" << endl;
        cout << "Result: ";

        try
        {
            Parser p(inputStr);
            Calculator c = p.getExression();
            if (enterPressed)
            {
                enterPressed = false;
                const Node& r = c.getResult();
                r.print(cout);
            }
        }
        catch (bad_cast& e)
        {
            cerr << "invalid order" << endl;
        }
        catch (exception& e)
        {
            cerr << "" << e.what() << endl;
        }
        catch(...)
        {
            cerr << "" << "unknown exception" << endl;
        }

        byteFirst = getch();
        if (byteFirst == 224)
            byteSecond = getch();
        else
            byteSecond = 0;

        if (byteFirst == 27) /// escape
            return 0;

        else if (byteFirst == 13) /// enter
            enterPressed = true;

        else if (byteFirst == 8) /// backspace
        {
            if (inputStr.size() == 0)
                continue;
            if (lastSymbol == ')')
                bracketsState++;
            if (lastSymbol == '(')
                bracketsState--;
            inputStr.resize(inputStr.size()-1);
        }

        else if (byteFirst == 127) /// ctrl+backspace
        {
            inputStr.clear();
        }

        else if (rightSymbols.find(byteFirst) == rightSymbols.end())
            continue;

        else if (byteFirst >= '0' && byteFirst <= '9' || byteFirst == '.')
            if (lastSymbol == ')' || lastSymbol == 'x')
            {
                inputStr += '*' ;
                inputStr +=  byteFirst;
            }
            else
                inputStr += byteFirst;

        else if (operations.find(byteFirst) != operations.end())
            if ((byteFirst == '*' || byteFirst == '/') && lastSymbol == '(')
                continue;
            else
                inputStr += byteFirst;

        else if (byteFirst == 'x')
            if (lastSymbol >= '0' && lastSymbol <= '9' || lastSymbol == ')' || lastSymbol == 'x')
            {
                inputStr += '*' ;
                inputStr +=  byteFirst;
            }
            else
                inputStr += byteFirst;

        else if (byteFirst == ' ')
            inputStr += byteFirst;

        else if (byteFirst == '(')
            if (lastSymbol >= '0' && lastSymbol <= '9' || lastSymbol == ')' || lastSymbol == 'x')
            {
                inputStr += '*';
                inputStr += byteFirst;
                bracketsState++;
            }
            else
            {
                inputStr += byteFirst;
                bracketsState++;
            }

        else if (byteFirst == ')')
            if (bracketsState)
            {
                inputStr += byteFirst;
                bracketsState--;
            }
    }
}



