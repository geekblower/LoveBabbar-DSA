#include <bits/stdc++.h>
using namespace std;

void phoneKeypad(string digits, vector<string> &solution, string output, string mapping[], int index) {
    if(index == digits.length()) {
        solution.push_back (output);
        return;
    }

    int number = digits[index] - '0';
    string str = mapping[number];

    for(int i=0; i<str.length(); i++) {
        output.push_back (str[i]);
        phoneKeypad(digits, solution, output, mapping, index+1);
        output.pop_back();
    }
}

vector<string> letterCombination(string digits) {
    vector<string> solution;

    if(digits.length() == 0) {
        return solution;
    }
    
    string output;
    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    phoneKeypad(digits, solution, output, mapping, index);

    return solution;
}

int main() {
    string digits;

    cout << "Enter the digits : ";
    getline(cin, digits);

    vector<string> solution = letterCombination(digits);

    cout << "All combinations : " << endl;
    for(int i=0; i<solution.size(); i++) {
        cout << "{ " << solution[i] << " }" << endl;
    }

    return 0;
}