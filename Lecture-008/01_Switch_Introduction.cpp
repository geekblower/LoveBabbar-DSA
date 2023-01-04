#include <iostream>
using namespace std;

int main() {
    int num = 2;

    switch(num) {
        case 1 : cout<<"First"<<endl;
            break;
        
        case 2 :
            cout<<"Second"<<endl;
            break;
            
        default :
            cout<<"Default case"<<endl;
    }

    return 0;
}