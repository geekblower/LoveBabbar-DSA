#include <iostream>
#include <string>
using namespace std;

string removeDuplicates(string s) {
    string::iterator it = s.begin();

    for(int i=0; i<s.length()-1; i++) {
        if(s[i] == s[i+1]) {
            s.erase(it, 2);
            i -= 2;
        }
    }
}

int main() {
    string str;

    cout<<"Enter the string : ";
    cin>>str;

    str = removeDuplicates(str);

    cout<<"String after removing all duplicates : "<<str;

    return 0; 
}