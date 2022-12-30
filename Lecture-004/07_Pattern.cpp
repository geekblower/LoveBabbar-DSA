#include <iostream>
using namespace std;

int main() {
    /*
    1
    2 3
    3 4 5
    4 5 6 7
    */

    int n;

    cout<<"Enter the value of n : ";
    cin>>n;

    int row = 1;

    while(row <= n) {
        int col = 1;

        while(col <= row) {
            cout<< row+col-1 <<" ";
            col = col + 1;
        }

        cout<<endl;
        row = row + 1;
    }
}