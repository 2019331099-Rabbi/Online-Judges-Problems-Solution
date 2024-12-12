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
    int memo[301];
    Solution() {
        memset(memo, -1, sizeof(memo));
    }

    bool isPossible(int pos, string s, unordered_set <string> &ust) {
        int len = s.size();
        if (pos == len) return true;
        if (memo[pos] != -1) return memo[pos];

        string word = "";
        bool ans = false;
        for (int i = pos; i < len; i++) {
            word += s[i];
            if (ust.find(word) != ust.end()) {
                ans = memo[pos] = isPossible(i + 1, s, ust);
                if (ans) return ans;
            }
        }
        return ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set <string> ust;
        for (auto &word: wordDict) ust.insert(word);
        return isPossible(0, s, ust);
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    Solution *soln = new Solution();

    string s = "applepenapple";
    vector <string> wordDict = {"apple","pen"};

    cout << soln->wordBreak(s, wordDict) << endl;
    return 0;
}