#include <iostream>
using namespace std;

int main() {
    int amount;
    int n100=0, n50=0, n20=0, n1=0;

    cout<<"Enter the amount : ";
    cin>>amount;

    switch(amount >= 100) {
        case 1 :
            n100 = amount/100;
            amount %= 100;
    }

    switch(amount >= 50) {
        case 1 :
            n50 = amount/50;
            amount %= 50;
    }

    switch(amount >= 20) {
        case 1 :
            n20 = amount/20;
            amount %= 20;
    }

    n1 = amount;

    cout<<"100 Rupees note = "<<n100<<endl;
    cout<<"50 Rupees note = "<<n50<<endl;
    cout<<"20 Rupees note = "<<n20<<endl;
    cout<<"1 Rupees note = "<<n1<<endl;

    return 0;
}