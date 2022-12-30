#include <iostream>
using namespace std;

int main() {
    /*
          1
        1 2 1
      1 2 3 2 1
    1 2 3 4 3 2 1
    */

    int n;

    cout<<"Enter the value of n : ";
    cin>>n;

    int row = 1;

    while(row <= n) {
        int col = 0;

        while(col < n-row) {
            cout<<"  ";
            col = col + 1;
        }

        int count = 1;

        while(count <= row) {
            cout<<count<<" ";
            count = count + 1;
        }

        count = count - 1;

        while(count > 1) {
            count = count - 1;
            cout<<count<<" ";
        }

        cout<<endl;
        row = row + 1;
    }
}