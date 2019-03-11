#include <iostream>
using namespace std;
#include "Fraction.cpp"

int main(){
    
    Fraction f1(11,2);
    Fraction f2(12,4);

    f1.print();
    f1.add(f2);
    f1.print();
}