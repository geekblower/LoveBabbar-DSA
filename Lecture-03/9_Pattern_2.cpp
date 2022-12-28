#include <iostream>
using namespace std;

int main() {
    /*
        1 1 1 1
        2 2 2 2
        3 3 3 3
        4 4 4 4
    */

    int n;

    cout<<"Enter the value of n : ";
    cin>>n;

    int i = 1;

    while(i <= n) {
        int j = 1;

        while(j<=n) {
            cout<<i<<" ";
            j = j + 1;
        }

        cout<<endl;
        i = i + 1;
    }
}