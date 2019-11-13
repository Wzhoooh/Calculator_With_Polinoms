#include <iostream>
#include <climits>
//#include <windows.h>
#include "Calculator.h"

using namespace std;

void printMap(map_int_LD source)
{
    for (auto i : source)
        cout << i.first << " " << i.second << endl;
}

int main()
{
    for(;;)
    {
        try
        {
            string str;
            getline(cin, str);
            system("cls");
            cout << str << endl;
            if (str.size() == 0)
                continue;

            Parser p(str);
            Calculator c = p.getExression();
            cout << endl << "-----------------------------" << endl;
            c.print(cout);
            cout << endl << "-----------------------------" << endl;
            const Node& r = c.getResult();
            r.print(cout);
            cout << endl << "=============================" << endl;
        }
        catch (bad_cast& e)
        {
            cerr << "ERROR: invalid order" << endl;
        }
        catch (exception& e)
        {
            cerr << "ERROR: " << e.what() << endl;
        }
        catch(...)
        {
            cerr << "ERROR: " << "unknown exception" << endl;
        }
    }


    cout.precision(10);
    const Node& pol_1 = Polinom(map_int_LD{ {0, 5.44}, {2, 3} });
    const Node& pol_2 = Polinom(map_int_LD({ {1, 5}, {2, 3} }));
    const Node& pol_3 = Polinom(map_int_LD({ {0, 5}, {2, 3} }));
    const Node& pol_4 = Polinom(map_int_LD({ {0, 7} }));
    const Node& pol_5 = Polinom(map_int_LD({ {0, 2} }));
    const Node& pol_6 = Polinom(map_int_LD({ {0, -0.5} }));

    const Node& add = BinaryAdd();
    const Node& minus = UnaryMinus();
    const Node& mul = BinaryMul();
    const Node& div = BinaryDiv();
    const Node& pow = BinaryPow();
    const Node& op_br = Bracket(true);
    const Node& cl_br = Bracket(false);

    list_node l;
    l.push_back(pol_3);
    l.push_back(mul);
    l.push_back(minus);
    l.push_back(op_br);
    l.push_back(pol_1);
    l.push_back(add);
    l.push_back(pol_2);
    l.push_back(cl_br);
    l.push_back(pow);
    l.push_back(pol_4);
//    l.push_back(pow);
//    l.push_back(pol_6);
    l.push_back(div);
    l.push_back(pol_5);

    Calculator c(l);
    cout << endl << "-----------------------------" << endl;
    c.print(cout);
    cout << endl << "-----------------------------" << endl;
    const Node& r = c.getResult();
    r.print(cout);
    return 0;

//    const NodeTwoArguments& oper = BinarySub();
//    const NodeTwoArguments& oper = BinaryAdd();
//    const NodeTwoArguments& oper = BinaryMul();
//    const NodeTwoArguments& oper = BinaryDiv();
    const NodeTwoArguments& oper = BinaryPow();

    oper.print(cout);
    cout << endl << "-----------------------------" << endl;
    const Polinom& resultedPolinom = dynamic_cast < const Polinom& > (oper.getValue(pol_1, pol_2));

    resultedPolinom.print(cout);
    cout << endl;

//    map_int_LD resultedMap = (dynamic_cast < const Polinom& > (resultedPolinom)).getCoefficients();
//    printMap(resultedMap);

}



