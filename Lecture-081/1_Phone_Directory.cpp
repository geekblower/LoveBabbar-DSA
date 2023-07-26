#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch) {
            data = ch;
            isTerminal = false;

            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
        }
};

class Trie {
    public:
        TrieNode* root;

        Trie() {
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* &root, string word) {
            if(word.length() == 0) {
                root->isTerminal = true;
                return;
            }

            TrieNode* child;
            int index = word[0] - 'a';

            if(root->children[index] == NULL) {
                child = new TrieNode(word[0]);
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

void printSuggetions(TrieNode* curr, vector<string> &temp, string prefix) {
    // Terminal Node - Suggestion Found
    if(curr->isTerminal) {
        temp.push_back(prefix);
    }

    for(char ch = 'a'; ch <= 'z'; ch++) {
        TrieNode* next = curr->children[ch - 'a'];

        if(next != NULL) {
            prefix.push_back(ch);
            printSuggetions(next, temp, prefix);
            prefix.pop_back();
        }
    }
}

vector< vector<string> > getSuggestions(TrieNode* root, string query) {
    vector< vector<string> > answer;
    TrieNode* prev = root;
    string prefix = "";

    for(int i=0; i<query.length(); i++) {
        char lastChar = query[i];
        prefix.push_back(lastChar);

        // Check for last character
        TrieNode* curr = prev->children[lastChar - 'a'];

        // Not found
        if(curr == NULL) {
            break;
        }

        // Found
        vector<string> temp;
        printSuggetions(curr, temp, prefix);
        answer.push_back(temp);
        temp.clear();
        prev = curr;
    }

    return answer;
}

vector< vector<string> > phoneDirectory(vector<string> contactList, string query) {
    // Creation of trie
    Trie* T = new Trie();

    // Insert all strings in trie
    for(int i=0; i<contactList.size(); i++) {
        T->insertNode(contactList[i]);
    }

    // Return function
    return getSuggestions(T->root, query);
}

int main() {
    vector<string> contactList;
    string query;
    vector< vector<string> > suggestions;

    string temp;
    cout << "Enter the strings (-1 to stop) : ";
    cin >> temp;
    while(temp != "-1") {
        contactList.push_back(temp);
        cin >> temp;
    }

    cout << "Enter the query string : ";
    cin >> query;

    suggestions = phoneDirectory(contactList, query);

    for(vector<string> x : suggestions) {
        for(string y : x) {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}