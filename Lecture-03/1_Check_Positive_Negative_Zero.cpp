#include <iostream>
using namespace std;

int main() {
    int n;

    cout<<"Enter the value of n : ";
    cin>>n;

    if(n<0) {
        cout<<"n is negative !"<<endl;
    } else if(n>0) {
        cout<<"n is positive !"<<endl;
    } else {
        cout<<"n is zero !"<<endl;
    }
}