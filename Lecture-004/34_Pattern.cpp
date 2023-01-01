#include <iostream>
using namespace std;

int main() {
    /*
    *                 *
    * *             * *
    * * *         * * *
    * * * *     * * * *
    * * * * * * * * * *
    * * * *     * * * *
    * * *         * * *
    * *             * *
    *                 *
    */

    int n;

    cout<<"Enter the value of n : ";
    cin>>n;

    int row = 1;

    while(row <= n) {
        int col = 1;

        while(col <= row) {
            cout<<"* ";
            col = col + 1;
        }

        col = 1;

        while(col <= n-row) {
            cout<<"    ";
            col = col + 1;
        }

        col = 1;

        while(col <= row) {
            cout<<"* ";
            col = col + 1;
        }

        cout<<endl;
        row = row + 1;
    }

    row = 1;

    while(row < n) {
        int col = 1;

        while(col < n-row+1) {
            cout<<"* ";
            col = col + 1;
        }

        while(col <= n) {
            cout<<"    ";
            col = col + 1;
        }

        col = 1;

        while(col < n-row+1) {
            cout<<"* ";
            col = col + 1;
        }

        cout<<endl;
        row = row + 1;
    }

    return 0;
}