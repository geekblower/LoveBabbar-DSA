#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        int childCount;

        TrieNode(char data) {
            this->data = data;
            this->isTerminal = false;
            this->childCount = 0;

            for(int i=0; i<26; i++) {
                this->children[i] = NULL;
            }
        }
};

class Trie {
    public:
        TrieNode* root;

        Trie() {
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root, string word) {
            if(word.length() == 0) {
                root->isTerminal = true;
                return;
            }

            // Assuming the string is in lowercase
            int index = word[0] - 'a';
            TrieNode* child;

            if(root->children[index] == NULL) { 
                child = new TrieNode(word[0]);
                root->childCount++;
                root->children[index] = child;
            } else {
                child = root->children[index];
            }

            insertUtil(child, word.substr(1));
        }

        void insertNode(string word) {
            insertUtil(root, word);
        }
};

string longestCommonPrefix(vector<string> str) {
    string ans = "";
    Trie* t = new Trie();

    // insert all strings in trie;
    for(int i=0; i<str.size(); i++) {
        t->insertNode(str[i]);
    }

    TrieNode* temp = t->root;

    for(int i=0; i<str[0].length(); i++) {
        if(temp->childCount == 1) {
            ans.push_back(str[0][i]);

            int index = str[0][i] - 'a';
            temp = temp->children[index];
        } else {
            break;
        }

        if(temp->isTerminal) {
            break;
        }
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