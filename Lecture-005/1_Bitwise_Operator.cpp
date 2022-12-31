#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int b = 7;
    int value;

    value = a&b;
    cout<<"a & b = "<<value<<endl;

    value = a|b;
    cout<<"a | b = "<<value<<endl;
    
    value = ~a;
    cout<<"~a = "<<value<<endl;
    
    value = ~b;
    cout<<"~b = "<<value<<endl;
    
    value = a^b;
    cout<<"a ^ b = "<<value<<endl;
    
    return 0;
}