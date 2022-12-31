#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 20;

    a = a << 1;
    cout<<"a after left shift = "<<a<<endl;

    b = b >> 1;
    cout<<"b after right shift = "<<b<<endl;
    
    return 0;
}