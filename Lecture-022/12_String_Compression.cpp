#include <iostream>
#include <string>
using namespace std;

string stringCompression(string s) {
    string ans = "";

    for(int i=0; i<s.length(); i++) {
        int count = 0;
        char temp = s[i];

        while(i<s.length() && s[i]==temp) {
            i++;
            count++;
        }
        i--;

        ans.push_back(temp);
        if(count > 1) {
            char ch = count + '0';
            ans.push_back(ch);
        }
    }

    return ans;
}

int main() {
    string str;

    cout<<"Enter the string : ";
    getline(cin, str);

    string ans = stringCompression(str);

    cout<<"Compressed string : "<<ans;

    return 0; 
}