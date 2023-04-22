#include <bits/stdc++.h>
using namespace std;

bool redundantBracket(string str) {
    stack<char> st;

    for(int i=0; i<str.length(); i++) {
        bool redundancy = true;
        char ch = str[i];

        if(ch=='(' || ch=='+' || ch=='-' || ch=='-' || ch=='/') {
            st.push(ch);
        } else {

            if(ch == ')') {

                while(st.top() != '(') {
                    char top = st.top();
                    if(top=='+' || top=='-' || top=='-' || top=='/') {
                        redundancy = false;
                    }
                    st.pop();
                }
                
                if(redundancy == true) {
                    return false;
                }

                st.pop();
            }

        } 
    }

    return true;
}

int main() {
    string str;
    stack<char> st;
    
    cout << "Enter the expression : ";
    getline(cin, str);

    if(redundantBracket(str)) {
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }

    return 0;
}