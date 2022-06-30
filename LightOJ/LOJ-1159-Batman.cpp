#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 51
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
Problem Link: https://lightoj.com/problem/batman

1

abcdef
cdef
dcdef
*/
int memo[sz][sz][sz];
string s1, s2, s3;

void init()
{
    memset(memo, -1, sizeof(memo));
}

int LCS(int pos1, int pos2, int pos3)
{
    if (pos1 == s1.size() || pos2 == s2.size() || pos3 == s3.size()) return 0;
    if (memo[pos1][pos2][pos3] != -1) return memo[pos1][pos2][pos3];

    if (s1[pos1] == s2[pos2] && s2[pos2] == s3[pos3]) return memo[pos1][pos2][pos3] = 1 + LCS(pos1 + 1, pos2 + 1, pos3 + 1);
    else {
        int val1 = LCS(pos1 + 1, pos2, pos3);
        int val2 = LCS(pos1, pos2 + 1, pos3);
        int val3 = LCS(pos1, pos2, pos3 + 1);
        return memo[pos1][pos2][pos3] = max({val1, val2, val3});
    }
}

void solve(int i)
{
    cin >> s1 >> s2 >> s3;
    init();
    cout << "Case " << i << ": " << LCS(0, 0, 0) << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}