#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

struct node
{
    int ending;
    node *next[26];
    node()
    {
        ending = 0;
        for (int i = 0; i < 26; i++) next[i] = NULL;
    }
};

struct TRIE
{
    node *root;
    TRIE()
    {
        root = new node();
    }

    void inseert_trie(string s, int pos)
    {
        node *tmp = root;
        for (int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a';
            if (tmp->next[x] == NULL) tmp->next[x] = new node();
            tmp = tmp->next[x];
        }
        tmp->ending = pos;
    }

    int search_trie(string s)
    {
        node *tmp = root;
        for (int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a';
            if (tmp->next[x] == NULL) return false;
            tmp = tmp->next[x];
        }
        return tmp->ending;
    }

    void delete_node(node *tmp)
    {
        for (int i=0; i<26; i++) {
            if (tmp->next[i]!=NULL) delete_node(tmp->next[i]);
        }
        delete tmp;
    }

    void delete_trie()
    {
        delete_node(root);
    }
};

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
    TRIE *tr = new TRIE();
    for (int i = 0; i < wordList.size(); i++) tr->inseert_trie(wordList[i], i+1);

    vector <bool> vis(wordList.size(), false);
    queue <pair <string, int>> pq;

    pq.push({beginWord, 1});

    while (!pq.empty()) {
        string u = pq.front().first;
        int cnt = pq.front().second;
        pq.pop();

        if (u == endWord) {
            tr->delete_trie();
            return cnt;
        }
        
        for (int i = 0; i < beginWord.size(); i++) {
            char ch = u[i];
            for (int j = 0; j < 26; j++) {
                char xx = 'a' + j;
                if (xx == u[i]) continue;
                u[i] = xx;
                int flag = tr->search_trie(u);
                if (flag && !vis[flag - 1]) {
                    pq.push({u, cnt + 1});
                    vis[flag - 1] = true;
                }
                u[i] = ch;
            }
        }
    }
    tr->delete_trie();
    return 0;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout << ladderLength(beginWord, endWord, wordList) << endl;

    return 0;

}