#include <iostream>
using namespace std;

int main() {
    char ch;

    cout<<"Enter the character : ";
    cin>>ch;

    if(ch>='A' && ch<='Z') {
        cout<<"Uppercase Character !"<<endl;
    } else if(ch>='a' && ch<='z') {
        cout<<"Lowercase Character !"<<endl;
    } else {
        cout<<"Number !"<<endl;
    }
}