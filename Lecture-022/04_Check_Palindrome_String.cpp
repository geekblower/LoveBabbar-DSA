#include <iostream>
using namespace std;

int main() {
    char name[50];
    
    cout<<"Enter string : ";
    cin>>name;

    int n = 10;
    int s = 0;
    int e = n-1;

    while(s<=e) {
        if(name[s] != name[e]) {
            cout<<"NO";
            break;
        }
        s++;
        e--;
    }

    cout<<"YES";

    return 0;
}