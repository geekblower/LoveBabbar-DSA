#include <bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch) {
            this->data = ch;
            this->isTerminal = false;

            for(int i=0; i<26; i++) {
                this->children[i] = NULL;
            }
        }
};

class Trie {
    public :
        TrieNode* root;

        Trie() {
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* &root, string word) {
            if(word.length() == 0) {
                root->isTerminal = true;
                return;
            }

            // Assumption : Word will be in CAPS
            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index] != NULL) {
                // Character Present
                child = root->children[index];
            } else {
                // Character Absent
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            // Recursion
            insertUtil(child, word.substr(1));
        }

        void insertNode(string word) {
            insertUtil(root, word);
        }

        bool searchUtil(TrieNode* root, string word) {
            // Base case
            if(word.length() == 0) {
                return root->isTerminal;
            }

            // Finding index through mapping
            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index] != NULL) {
                // Present
                child = root->children[index];
            } else {
                // Absent
                return false;
            }

            return searchUtil(child, word.substr(1));
        }

        bool search(string word) {
            return searchUtil(root, word);
        }

        bool removeUtil(TrieNode* root, string word) {
            // Base case
            if(word.length() == 0) {
                if(root->isTerminal) {
                    root->isTerminal = false;
                    return true;
                } else {
                    return false;
                }
            }

            // Finding index through mapping
            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index] != NULL) {
                // Present
                child = root->children[index];
            } else {
                // Absent
                return false;
            }

            return removeUtil(child, word.substr(1));
        }

        bool remove(string word) {
            return removeUtil(root, word);
        }

        bool eraseUtil(TrieNode* root, string word) {
            // Base case
            if(word.length() == 0) {
                if(root->isTerminal) {
                    root->isTerminal = false;
                    delete root;
                    return true;
                } else {
                    return false;
                }
            }

            // Finding index through mapping
            int index = word[0] - 'A';
            TrieNode* child;

            if(root->children[index] != NULL) {
                // Present
                child = root->children[index];
            } else {
                // Absent
                return false;
            }

            bool ans = eraseUtil(child, word.substr(1));
            delete child;
            return ans;
        }

        bool erase(string word) {
            return eraseUtil(root, word);
        }
};

int main() {

    Trie* T = new Trie();

    T->insertNode("AKASH");

    bool present = T->search("AKASH");

    if(present) {
        cout << "Word is Present!" << endl;
    } else {
        cout << "Word is Absent!" << endl;
    }

    T->erase("AKASH");
    present = T->search("AKASH");

    if(present) {
        cout << "Word is Present!" << endl;
    } else {
        cout << "Word is Absent!" << endl;
    }

    cout << T->root->children[0]->data << endl;
    T->insertNode("AKASH");
    present = T->search("AKASH");

    if(present) {
        cout << "Word is Present!" << endl;
    } else {
        cout << "Word is Absent!" << endl;
    }

    return 0;
}