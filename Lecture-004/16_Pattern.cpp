#include <iostream>
using namespace std;

int main() {
    /*
    D 
    C C
    B B B
    A A A A
    */

    int n;

    cout<<"Enter the value of n : ";
    cin>>n;

    int row = 1;

    while(row <= n) {
        int col = 1;

        while(col <= row) {
            char value = 'A' + n - row;
            cout<<value<<" ";
            col = col + 1;
        }

        cout<<endl;
        row = row + 1;
    }
}