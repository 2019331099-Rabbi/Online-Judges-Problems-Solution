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


class Solution {
public:
    vector<char> chs = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = beginWord.size();
        unordered_set <string> vis(wordList.begin(), wordList.end());

        queue <pair <string, int>> q;
        q.push({beginWord, 1});
        vis.insert(beginWord);

        while (!q.empty()) {
            string u = q.front().first;
            int cnt = q.front().second;
            if (u == endWord) return cnt;
            q.pop();

            for (int i = 0; i < len; i++) {
                char prev = u[i];
                for (auto ch: chs) {
                    u[i] = ch;
                    if (vis.find(u) != vis.end()) {
                        q.push({u, cnt + 1});
                        vis.erase(u);
                    }
                }
                u[i] = prev;
            }
        }
        return 0;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    string beginWord = "hit", endWord = "cog";
    vector <string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout << soln->ladderLength(beginWord, endWord, wordList) << endl;


}