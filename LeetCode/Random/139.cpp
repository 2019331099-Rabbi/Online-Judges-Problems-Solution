#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST 
using namespace std;

int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

struct node
{
    bool ending;
    node *next[26];
    node()
    {
        ending=false;
        for (int i=0; i<26; i++) next[i]=NULL;
    }
};

struct TRIE
{
    node *root;
    TRIE();
    void insert_trie(string);
    bool search_trie(string);
    void delete_trie();

    ///Utility function
    void delete_node(node *);
};

TRIE::TRIE()
{
    root=new node();
}

void TRIE::insert_trie(string s)
{
    node *tmp=root;
    int i, len=s.size(), x;
    for (i=0; i<len; i++) {
        x=s[i]-'a';
        if (tmp->next[x]==NULL) tmp->next[x]=new node();
        tmp=tmp->next[x];
    }
    tmp->ending=true;
}

bool TRIE::search_trie(string s)
{
    int i, x, len=s.size();
    node *tmp=root;
    for (i=0; i<len; i++) {
        x=s[i]-'a';
        if (tmp->next[x]==NULL) return false;
        tmp=tmp->next[x];
    }
    return tmp->ending;
}

void TRIE::delete_node(node *tmp)
{
    for (int i=0; i<26; i++) {
        if (tmp->next[i]!=NULL) delete_node(tmp->next[i]);
    }
    delete tmp;
}

void TRIE::delete_trie()
{
    delete_node(root);
}

bool wordBreak(string s, vector<string>& wordDict)
{
    TRIE *trie = new TRIE();
    for (const string &word: wordDict) trie->insert_trie(word);

    int len = s.size();
    queue <int> q;
    bool vis[len] = {false};

    auto processingSubsting = [&](int startPos)
    {
        node *tmp = trie->root;
        for (int i = startPos; i < len; i++) {
            int x = s[i] - 'a';
            if (tmp->next[x]) {
                tmp = tmp->next[x];
                if (tmp->ending && !vis[i]) q.push(i), vis[i] = true;
            }
            else break;
        }
    };

    processingSubsting(0);
    while (!q.empty()) {
        int pos = q.front();
        if (pos == len - 1) return true;
        q.pop();
        processingSubsting(pos + 1);
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    string s = "catsandog";
    vector <string> wordDict = {"cats","og","sand","and","cat"};

    cout << wordBreak(s, wordDict) << endl;

}