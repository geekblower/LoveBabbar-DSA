#include <iostream>
using namespace std;

// AP : 3*n + 7
int NthTerm(int n) {
    return 3*n + 7;
}

int main() {
    int n;

    cout<<"Enter the value of n : ";
    cin>>n;

    cout<<"Nth term of the AP = "<<NthTerm(n)<<endl;

    return 0;
}