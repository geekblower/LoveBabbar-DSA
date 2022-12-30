#include <iostream>
using namespace std;

int main() {
    /*
    1 2 3 4
    1 2 3 4
    1 2 3 4
    1 2 3 4
    */

    int n;

    cout<<"Enter the value of n : ";
    cin>>n;

    int row = 1;

    while(row <= n) {
        int col = 1;

        while(col <= n) {
            cout<<col<<" ";
            col = col + 1;
        }

        cout<<endl;
        row = row + 1;
    }
}