#include <iostream>
#include "Calculator.h"

using namespace std;

void printMap(map_int_LD source)
{
    for (auto i : source)
        cout << i.first << " " << i.second << endl;
}

int main()
{
    map_int_LD inputMap;
    inputMap.insert({0, 4});
    inputMap.insert({8, 100});
    inputMap.insert({3, 60});
    Node* pol = new Polinom(inputMap);

//    Node* uMinusNode = new UnaryMinus;
//    NodeOneArgument* uMinusNodeZero = static_cast < NodeOneArgument* > (uMinusNode);
//    Polinom* resutedPolinom = static_cast < Polinom* > (uMinusNodeZero->getValue(pol));

    Node* uPlusNode = new UnaryPlus;
    NodeOneArgument* uPlusNodeZero = static_cast < NodeOneArgument* > (uPlusNode);
    Polinom* resutedPolinom = static_cast < Polinom* > (uPlusNodeZero->getValue(pol));

    map_int_LD resultedMap =  resutedPolinom->getCoefficients();
    printMap(resultedMap);
}
