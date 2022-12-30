#include <iostream>
using namespace std;

int main() {
    /*
    1 1 1 1
      2 2 2
        3 3
          4
    */

    int n;

    cout<<"Enter the value of n : ";
    cin>>n;

    int row = 1;

    while(row <= n) {
        int col = 0;

        while(col < row) {
            cout<<"  ";
            col = col + 1;
        }

        while(col <= n) {
            cout<<row<<" ";
            col = col + 1;
        }

        cout<<endl;
        row = row + 1;
    }
}