#include <iostream>
using namespace std;

int main() {
    char name[50];
    
    cout<<"Enter string : ";
    // cin>>name;
    getline(cin, name);

    cout<<"Entered string : "<<name<<endl;

    return 0;
}
