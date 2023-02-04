#include <iostream>
#include <string>
using namespace std;

void removeOccurrences(string &s, string part) {

    while(s.length()!=0 && s.find(part) < s.length()) {
        s.erase(s.find(part), part.length());
    }

}

int main() {
    string str, part;

    cout<<"Enter the string : ";
    cin>>str;

    cout<<"Enter the target substring : ";
    cin>>part;

    removeOccurrences(str, part);

    cout<<"string after removeing all occurrences : "<<str;

    return 0; 
}