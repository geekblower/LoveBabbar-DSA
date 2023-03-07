#include <bits/stdc++.h>
using namespace std;

void solve(string str, vector<string> &solution, int index) {
    if(index == str.length()) {
        solution.push_back(str);
        return;
    }

    for(int i=index; i<str.length(); i++) {
        swap(str[i], str[index]);
        solve(str, solution, index+1);
        swap(str[i], str[index]);
    }
}

vector<string> permutations(string str) {
    vector<string> solution;
    int index = 0;

    solve(str, solution, index);
    sort(solution.begin(), solution.end());
    return solution;
}

int main() {
    string str;

    cout << "Enter the string : ";
    getline(cin, str);

    vector<string> solution = permutations(str);

    cout << "All permutations : " << endl;
    for(int i=0; i<solution.size(); i++) {
        cout << "{ " << solution[i] << " }" << endl;
    }

    return 0;
}