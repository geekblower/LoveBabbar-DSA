#include<iostream>
using namespace std;

int main() {

    int arr[5] = {1,2,3,4,5};
    char ch[6] = "abcde";


    cout << "arr : " << arr << endl;
    cout << "ch : " << ch << endl;
    
    char *c = &ch[0];
    // Prints entire string
    cout << c << endl;

    char temp = 'z';
    char *p = &temp;
    cout << "p : " << p << endl;

    return 0;
}