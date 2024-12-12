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

class WordDictionary {
public:
    
    TrieNode *root;
    WordDictionary() {
        root = new TrieNode();
        ios::sync_with_stdio(false); cin.tie(nullptr);
    }
    
    void addWord(string word) {
        TrieNode *tmp = root;
        for (auto ch: word) {
            int x = ch - 'a';
            if (tmp->next[x] == NULL) tmp->next[x] = new TrieNode();
            tmp = tmp->next[x];
        }
        tmp->ending = true;
    }
    
    bool findWord(string word, int pos, TrieNode *node) {
        if (pos == word.size()) return node->ending;

        char ch = word[pos];
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->next[i] && findWord(word, pos + 1, node->next[i])) return true;
            }
        }
        else {
            int x = ch - 'a';
            if (node->next[x]) return findWord(word, pos + 1, node->next[x]);
        }
        return false;
    }

    bool search(string word) {
        return findWord(word, 0, root);
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    WordDictionary *wordDictionary = new WordDictionary();
    wordDictionary->addWord("xgvk");
    wordDictionary->addWord("wykzbvwdsoyfowqicymzd");
    wordDictionary->addWord("xajbtjyjuwgoynjgu");
    cout << wordDictionary->search("wykzbvwdso..owqicymzd") << endl; // return False




}

