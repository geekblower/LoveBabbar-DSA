#include <iostream>
using namespace std;

int main() {
    /*
    1 2 3 4 5 16 17 18 19 20
    6 7 8 9 21 22 23 24
    10 11 12 25 26 27
    13 14 28 29
    15 30
    */
 
    int n;

    cout<<"Enter the value of n : ";
    cin>>n;

    int row = 1;
    int count1 = 1;
    int count2 = ((n*(n+1)) / 2) + 1;

    while(row <= n) {
        int col = 0;

        while(col <= n-row) {
            cout<<count1++<<" ";
            col = col + 1;
        }
        
        col = 0;
        while(col <= n-row) {
            cout<<count2++<<" ";
            col = col + 1;
        }
        // col = 1;

        // while(col < n-row+1) {
        //     cout<<"* * ";
        //     col = col + 1;
        // }

        // col = row;

        // while(col >= 1) {
        //     cout<<col<<" ";
        //     col = col - 1;
        // }

        cout<<endl;
        row = row + 1;
    }

    return 0;
}