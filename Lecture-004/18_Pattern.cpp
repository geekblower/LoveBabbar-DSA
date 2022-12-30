#include <iostream>
using namespace std;

int main() {
    /*
    A B C
    B C D
    C D E
    */

    int n;

    cout<<"Enter the value of n : ";
    cin>>n;

    int row = 1;

    while(row <= n) {
        int col = 1;

        while(col <= n) {
            char value = 'A' + row + col - 2;
            cout<<value<<" ";
            col = col + 1;
        }

        cout<<endl;
        row = row + 1;
    }
}