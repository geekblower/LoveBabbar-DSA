#include <iostream>
using namespace std;

int main() {
    /*
    * * * *
    * * *
    * *
    * 
    */

    int n;

    cout<<"Enter the value of n : ";
    cin>>n;

    int row = 1;

    while(row <= n) {
        int col = 0;

        while(col <= n-row) {
            cout<<"* ";
            col = col + 1;
        }

        cout<<endl;
        row = row + 1;
    }
}