#include <iostream>
using namespace std;

int main() {
    /*
    1 2 3
    4 5 6
    7 8 9
    */

    int n;

    cout<<"Enter the value of n : ";
    cin>>n;

    int row = 1;
    int count = 1;

    while(row <= n) {
        int col = 1;

        while(col <= n) {
            cout<<count<<" ";
            col = col + 1;
            count = count + 1;
        }

        cout<<endl;
        row = row + 1;
    }
}