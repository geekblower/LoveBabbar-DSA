#include <bits/stdc++.h>
using namespace std;

bool matches(char a, char b) {
    switch(a) {
        case ')':
            return (b == '(') ? true : false;
        case '}':
            return (b == '{') ? true : false;
        case ']':
            return (b == '[') ? true : false;
    }
}

bool isValid(string str) {
    stack<char> st;

    for(int i=0; i<str.length(); i++) {
        char ch = str[i];

        if(ch=='(' || ch=='{' || ch=='[') {
            st.push(ch);
        } else {
            if(!st.empty() && matches(ch, st.top())) {
                st.pop();
            } else {
                return false;
            }
        }
    }

    return (st.empty()) ? true : false;
}

int main() {
    string str;

    cout << "Enter the expression : ";
    getline(cin, str);

    if(isValid(str)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}