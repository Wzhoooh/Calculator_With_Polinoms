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
    inputMap.insert({0, -3});
    inputMap.insert({1, 1});
    Node* pol = new Polinom(inputMap);

    map_int_LD inputMapTwo;
    inputMapTwo.insert({0, -3});
    inputMapTwo.insert({1, 1});
    Node* polTwo = new Polinom(inputMapTwo);

//    Node* uMinusNode = new UnaryMinus;
//    NodeOneArgument* uMinusNodeZero = static_cast < NodeOneArgument* > (uMinusNode);
//    Polinom* resutedPolinom = static_cast < Polinom* > (uMinusNodeZero->getValue(pol));

//    Node* uPlusNode = new UnaryPlus;
//    NodeOneArgument* uPlusNodeZero = static_cast < NodeOneArgument* > (uPlusNode);
//    Polinom* resutedPolinom = static_cast < Polinom* > (uPlusNodeZero->getValue(pol));

//    Node* bAddNode = new BinaryAdd;
//    NodeTwoArguments* AddNodeTwo = static_cast < NodeTwoArguments* > (bAddNode);
//    Polinom* resutedPolinom = static_cast < Polinom* > (AddNodeTwo->getValue(pol, polTwo));

    Node* bMulNode = new BinaryMul;
    NodeTwoArguments* MulNodeTwo = dynamic_cast < NodeTwoArguments* > (bMulNode);
    Polinom* resutedPolinom = dynamic_cast < Polinom* > (MulNodeTwo->getValue(pol, polTwo));

    map_int_LD resultedMap =  resutedPolinom->getCoefficients();
    printMap(resultedMap);

}
catch (exception* e)
{
    cout << e->what();
}
catch(...)
{
    cout << "some exception";
}
}



