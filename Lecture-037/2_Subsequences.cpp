#include <bits/stdc++.h>
using namespace std;

void solve(string str, vector<string> &solution, string output, int index) {
    if(index == str.length()) {
        if(output.length() > 0) {
            solution.push_back(output);
        }
        return;
    }
    solve(str, solution, output, index+1);

    output.push_back(str[index]);
    solve(str, solution, output, index+1);
}

vector<string> subsequences(string str) {
    vector<string> solution;
    string output;
    int index = 0;

    solve(str, solution, output, index);

    return solution;
}

int main() {
    string str;

    cout << "Enter the string : ";
    getline(cin, str);

    vector<string> solution = subsequences(str);

    cout << "All subsequences : " << endl;
    for(int i=0; i<solution.size(); i++) {
        cout << "{ " << solution[i] << " }" << endl;
    }

    return 0;
}