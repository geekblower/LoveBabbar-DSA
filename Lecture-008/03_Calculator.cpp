#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout<<"Enter the value of a : ";
    cin>>a;

    cout<<"Enter the value of b : ";
    cin>>b;

    char op;
    cout<<"Enter the operation you want to perform : ";
    cin>>op;

    switch(op) {
        case '+' : cout<<a<<" "<<op<<" "<<b<<" = "<<a+b<<endl;
            break;
        
        case '-' : cout<<a<<" "<<op<<" "<<b<<" = "<<a-b<<endl;
            break;
        
        case '*' : cout<<a<<" "<<op<<" "<<b<<" = "<<a*b<<endl;
            break;
        
        case '/' : cout<<a<<" "<<op<<" "<<b<<" = "<<a/b<<endl;
            break;
            
        default :
            cout<<"Please enter a valid operator !"<<endl;
    }

    return 0;
}