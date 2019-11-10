#include <iostream>
#include <climits>
#include "Calculator.h"

using namespace std;

void printMap(map_int_LD source)
{
    for (auto i : source)
        cout << i.first << " " << i.second << endl;
}

int main()
{
try
{
    cout.precision(10);
    map_int_LD inputMap;
    inputMap.insert({0, -2});
//    inputMap.insert({1, 1});
//    inputMap.insert({6, 4});
    const Node& pol = Polinom(inputMap);
    pol.print(cout);
    cout << endl;

    map_int_LD inputMapTwo;
    inputMapTwo.insert({0, 10000});
//    inputMapTwo.insert({2, -1});
    const Node& polTwo = Polinom(inputMapTwo);
    polTwo.print(cout);
    cout << endl;

    const Node& Add = BinaryAdd();

//    const NodeTwoArguments& oper = BinarySub();
//    const NodeTwoArguments& oper = BinaryAdd();
//    const NodeTwoArguments& oper = BinaryMul();
//    const NodeTwoArguments& oper = BinaryDiv();
    const NodeTwoArguments& oper = BinaryPow();

    oper.print(cout);
    cout << endl << "-----------------------------" << endl;
    const Polinom& resultedPolinom = dynamic_cast < const Polinom& > (oper.getValue(pol, polTwo));

    resultedPolinom.print(cout);
    cout << endl;

//    map_int_LD resultedMap = (dynamic_cast < const Polinom& > (resultedPolinom)).getCoefficients();
//    printMap(resultedMap);

}
catch (exception& e)
{
    cout << e.what() << endl;
}
catch(...)
{
    cout << "some exception" << endl;
}
}



