#include <bits/stdc++.h>
using namespace std;

int main() {
    string str, answer;
    stack<char> s;

    cout << "Enter the string : ";
    getline(cin, str);

    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        s.push(ch);
    }

    while(! s.empty()) {
        char ch = s.top();
        answer.push_back(ch);
        s.pop();
    }

    cout << "Original string : ";
    cout << str;
    cout << "\nReversed string : ";
    cout << answer;

    return 0;
}