#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1001
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST 
using namespace std;

int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

class TrieNode {
public:
    int ending;
    unordered_map <char, TrieNode*> next;
    TrieNode() {
        ending = -1;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string word, int pos) {
        TrieNode *node = root;
        for (auto ch: word) {
            if (node->next.find(ch) == node->next.end()) node->next[ch] = new TrieNode();
            node = node->next[ch];
        }
        node->ending = pos;
    }
};

class Solution {
public:
    vector <int> ansIndexs;

    void solve(vector<vector<char>>& board, int xi, int yi, TrieNode *node) {
        char ch = board[xi][yi];
        if (board[xi][yi] == '#' || node->next.find(ch) == node->next.end()) return;

        node = node->next[ch];
        if (node->ending >= 0) ansIndexs.push_back(node->ending), node->ending = -1;

        int n = board.size(), m = board[0].size();
        ch = board[xi][yi];
        board[xi][yi] = '#';
        for (int i = 0; i < 4; i++) {
            int xf = xi + row[i];
            int yf = yi + col[i];
            if (xf >= 0 && xf < n && yf >= 0 && yf < m) solve(board, xf, yf, node);
        }
        board[xi][yi] = ch;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *trie = new Trie();
        TrieNode *root = trie->root;
        for (int i = 0; i < words.size(); i++) trie->insert(words[i], i);

        
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) solve(board, i, j, root);
        }

        vector <string> ans;
        for (auto index: ansIndexs) ans.push_back(words[index]);
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution *soln = new Solution();

    vector<vector<char>> board = {
        {'a', 'b', 'c'},
        {'a', 'e', 'd'},
        {'a', 'f', 'g'}
    };

    // Words initialization
    vector<string> words = {"abcdefg", "gfedcbaaa", "eaabcdgfa", "befa", "dgc", "ade"};
    // vector<string> words = {"ade"};
    

    vector <string> resutls = soln->findWords(board, words);
    for (auto s: resutls) cout << s << endl;

    return 0;
}

