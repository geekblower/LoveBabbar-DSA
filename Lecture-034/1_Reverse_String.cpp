#include <bits/stdc++.h>
using namespace std;

void revString(string &s, int start, int end) {
    if(start > end) {
        return;
    }

    swap(s[start], s[end]);
    revString(s, start+1, end-1);
}

int main() {
    string str;

    cout << "Enter the string : ";
    getline(cin, str);

    revString(str, 0, str.length()-1);

    cout << "Reversed string : " << str << endl;

    return 0;
}