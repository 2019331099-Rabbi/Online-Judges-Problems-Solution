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
    string s1, s2, s3;
    int memo[101][101][2];
    bool dp(int pos1, int pos2, int prev, int cnt1, int cnt2) {
        int pos = pos1 + pos2;
        if (pos == s3.size()) return abs(cnt1 - cnt2) <= 1;
        if (memo[pos1][pos2][prev] != -1) return memo[pos1][pos2][prev];

        if (s3[pos] == s1[pos1]) {
            if (prev == 1) cnt1++, prev = 0;
            bool flag = memo[pos1][pos2][prev] = dp(pos1 + 1, pos2, prev, cnt1, cnt2);
            if (flag) return true;
        }
        if (s3[pos] == s2[pos2]) {
            if (prev == 0) cnt2++, prev = 1;
            bool flag = memo[pos1][pos2][prev] = dp(pos1, pos2 + 1, prev, cnt1, cnt2);
            if (flag) return true;
        }
        return false;
    }

    void init(string a, string b, string c) {
        s1 = a, s2 = b, s3 = c;
        memset(memo, -1, sizeof(memo));
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        if (s3.size() == 0) return true;
        init(s1, s2, s3);
        return dp(0, 0, 0, 0, 0);
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    Solution *soln = new Solution();

    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    // string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";
    cout << soln->isInterleave(s1, s2, s3) << endl;

    return 0;
}