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
    unordered_map <char, TrieNode*> next;

    TrieNode() {
        ending = false;
    }
};

class Trie {
public:

    TrieNode *root;
    int mn;
    Trie(int x) {
        root = new TrieNode();
        mn = x;
    }
    
    void insert(string word) {
        int cnt = 0;
        TrieNode *tmp = root;
        for (auto ch: word) {
            if (tmp->next.find(ch) == tmp->next.end()) tmp->next[ch] = new TrieNode();
            if (tmp->next.size() > 1) break;
            cnt++;
            tmp = tmp->next[ch];
        }
        tmp->ending = true;
        mn = min(mn, cnt);
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie *trie = new Trie(INT32_MAX);
        for (auto xx: strs) {
            trie->insert(xx);
            if (!trie->mn) break;
        }
        return strs[0].substr(0, trie->mn);
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution *soln = new Solution();

    vector <string> strs = {"flower", "flow", "flight"};

    cout << soln->longestCommonPrefix(strs) << endl;

}