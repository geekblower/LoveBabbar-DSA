#include <bits/stdc++.h>

using namespace std;

class Solution {
  void findPathHelper(int i, int j, vector < vector < int >> & a, int n, vector < string > & ans, string &move,
    vector < vector < int >> & vis) {
    if (i == n - 1 && j == n - 1) {
      ans.push_back(move);
      return;
    }

    //DLRU Lexographic order

    // downward
    if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1) {
      vis[i][j] = 1;
      move.push_back('D');
      findPathHelper(i + 1, j, a, n, ans, move, vis);
      vis[i][j] = 0;
      move.pop_back(); //either write this or pass the move string without by ref
    }

    // left
    if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1) {
      vis[i][j] = 1;
      move.push_back('L');
      findPathHelper(i, j - 1, a, n, ans, move, vis);
      vis[i][j] = 0;
      move.pop_back();
    }

    // right 
    if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1) {
      vis[i][j] = 1;
      move.push_back('R');
      findPathHelper(i, j + 1, a, n, ans, move, vis);
      vis[i][j] = 0;
      move.pop_back();
    }

    // upward
    if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1) {
      vis[i][j] = 1;
      move.push_back('U');
      findPathHelper(i - 1, j, a, n, ans, move, vis);
      vis[i][j] = 0;
      move.pop_back();
    }

  }
  public:
    vector < string > findPath(vector < vector < int >> & m, int n) {
      vector < string > ans;
      vector < vector < int >> vis(n, vector < int > (n, 0));
      string s="";

      if (m[0][0] == 1) findPathHelper(0, 0, m, n, ans, s, vis);
      return ans;
    }
};

int main() { 
  int n = 4;

   vector < vector < int >> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};

  Solution obj;
  vector < string > result = obj.findPath(m, n);
  if (result.size() == 0)
    cout << -1;
  else
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
  cout << endl;

  return 0;
}
