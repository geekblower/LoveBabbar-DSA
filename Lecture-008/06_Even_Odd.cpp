#include <iostream>
using namespace std;

bool isEven(int x) {
    if(x&1) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int num;

    cout<<"Enter the num : ";
    cin>>num;

    if(isEven(num)) {
        cout<<"Even Number!"<<endl;
    } else {
        cout<<"Odd Number!"<<endl;
    }

    return 0;
}