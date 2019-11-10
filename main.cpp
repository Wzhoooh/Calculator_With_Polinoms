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
    map_int_LD inputMap;
    inputMap.insert({0, 2});
    inputMap.insert({1, -3});
    const Node& pol = Polinom(inputMap);
    pol.print(cout);
    cout << endl;

    map_int_LD inputMapTwo;
    inputMapTwo.insert({0, 4});
    inputMapTwo.insert({2, 5});
    const Node& polTwo = Polinom(inputMapTwo);
    polTwo.print(cout);
    cout << endl;

    const Node& Add = BinaryAdd();

//    const NodeTwoArguments& oper = BinarySub();
//    const NodeTwoArguments& oper = BinaryAdd();
    const NodeTwoArguments& oper = BinaryMul();
    const Polinom& resultedPolinom = dynamic_cast < const Polinom& > (oper.getValue(Add, polTwo));

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



