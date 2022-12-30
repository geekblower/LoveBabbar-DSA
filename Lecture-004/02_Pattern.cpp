#include <iostream>
using namespace std;

int main() {
    /*
    4 3 2 1
    4 3 2 1
    4 3 2 1
    4 3 2 1
    */

    int n;

    cout<<"Enter the value of n : ";
    cin>>n;

    int row = 1;

    while(row <= n) {
        int col= n;

        while(col>= 1) {
            cout<<col<<" ";
            col= col- 1;
        }

        cout<<endl;
        row = row + 1;
    }
}