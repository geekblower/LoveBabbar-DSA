#include <iostream>
using namespace std;

int main() {
    /*
    A A A
    B B B
    C C C
    */

    int n;

    cout<<"Enter the value of n : ";
    cin>>n;

    int row = 1;
    char count = 'A';

    while(row <= n) {
        int col = 1;

        while(col <= n) {
            char value = 'A' + row - 1;
            cout<<value<<" ";
            col = col + 1;
        }

        cout<<endl;
        count = count + 1;
        row = row + 1;
    }
}