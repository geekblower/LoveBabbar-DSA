#include <iostream>
using namespace std;

int main() {
    /*
    D
    C D
    B C D
    A B C D
    */

    int n;

    cout<<"Enter the value of n : ";
    cin>>n;

    int row = 1;

    while(row <= n) {
        int col = 1;

        while(col <= row) {
            char value = 'A' + n - row - 1 + col;
            cout<<value<<" ";
            col = col + 1;
        }

        cout<<endl;
        row = row + 1;
    }
}