#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> str) {
    string ans = "";
    for(int i=0; i<str[0].length(); i++) {
        char curr = str[0].at(i);

        // For comparison of current character with remaining string;
        for(int j=1; j<str.size(); j++) {
            if(str[j].at(i) != curr) {
                return ans;
            }
        }

        ans += curr;
    }

    return ans;
}

int main() {
    vector<string> str;

    cout << "Enter the strings (-1 to stop) : ";
    while(1) {
        string temp;
        cin >> temp;
        
        if(temp == "-1") {
            break;
        }

        str.push_back(temp);
    }

    string ans = longestCommonPrefix(str);

    cout << "Longest common prefix : " << ans << endl;

    return 0; 
}