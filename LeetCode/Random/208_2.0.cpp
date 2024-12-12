#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1001
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST 
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

class TrieNode {
public:
    bool ending;
    TrieNode *next[26];
    TrieNode() {
        ending = false;
        for (int i = 0; i < 26; i++) next[i] = NULL;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node = root;
        for (auto xx: word) {
            int x = xx - 'a';
            if (node->next[x] == NULL) node->next[x] = new TrieNode();
            node = node->next[x];
        }
        node->ending = true;
    }
    
    bool search(string word) {
        TrieNode *node = root;
        for (auto xx: word) {
            int x = xx - 'a';
            if (node->next[x] == NULL) return false;
            node = node->next[x];
        }
        return node->ending;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (auto xx: prefix) {
            int x = xx - 'a';
            if (node->next[x] == NULL) return false;
            node = node->next[x];
        }
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Trie *trie = new Trie();

    trie->insert("apple");
    cout << trie->search("apple") << endl;
    cout << trie->search("app") << endl;
    cout << trie->startsWith("app") << endl;
    trie->insert("app");
    cout << trie->search("app") << endl;


}