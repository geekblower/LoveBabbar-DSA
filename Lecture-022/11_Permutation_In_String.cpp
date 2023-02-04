#include <iostream>
#include <string>
using namespace std;

bool checkInclusion(string s1, string s2) {
    int count[26] = {0};

    for(int i=0; i<s1.length(); i++) {
        int index = s1[i] - 'a';
        count[index]++;
    }
}

int main() {
    string str1, str2;

    cout<<"Enter the first string : ";
    cin>>str1;

    cout<<"Enter the second string : ";
    cin>>str2;

    if(checkInclusion(str1, str2)) {
        cout<<"Permutation is present!";
    } else {
        cout<<"Permutation is not present";
    }

    return 0; 
}