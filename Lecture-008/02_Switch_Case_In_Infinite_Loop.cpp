#include <iostream>
using namespace std;

int main() {
    int num = 2;

    while(1) {
        switch(num) {
            case 1 : cout<<"First"<<endl;
                break;
            
            case 2 :
                cout<<"Second"<<endl;
                exit(0);
                break;
            
            default :
                cout<<"Default case"<<endl;
        }
    }

    return 0;
}