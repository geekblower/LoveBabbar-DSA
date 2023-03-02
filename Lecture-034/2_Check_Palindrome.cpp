#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start) {
    if(start >= s.length()/2) {
        return true;
    }

    if(s[start] != s[s.length()-start-1]) {
        return false;
    }

    isPalindrome(s, start+1);
}

int main() {
    string str;

    cout << "Enter the string : ";
    getline(cin, str);

    if(isPalindrome(str, 0)) {
        cout << "Palindrome!" << endl;
    } else {
        cout << "Not Palindrome!" << endl;
    }

    return 0;
}