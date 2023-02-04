#include <iostream>
#include <string>
using namespace std;

bool isSymbol(char ch) {
    if((ch>='0' && ch<='9') || (ch>='A' && ch<='Z') || (ch>='a' && ch<='z')) {
        return false;
    } else {
        return true;
    }
}

bool isPalindrome(string str) {
    int start = 0;
    int end = str.length() - 1;

    while(start < end) {
        while(start < end && isSymbol(str[start])) {
            start++;
        }

        while(start < end && isSymbol(str[end])) {
            end--;
        }

        if(tolower(str[start]) != tolower(str[end])) {
            return false;
        }

        start++;
        end--;
    }

    return true;
}

int main() {
    string str;
    
    cout<<"Enter string : ";
    cin>>str;

    if(isPalindrome(str)) {
        cout<<"Palindrome String!\n";
    } else {
        cout<<"Non-palindrome string!\n";
    }

    return 0;
}