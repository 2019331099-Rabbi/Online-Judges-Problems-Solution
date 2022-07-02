#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1e9 + 9
#define mod 100000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
Problem Link: https://www.spoj.com/problems/ADASEQEN/
*/

int n, m, value[sz], memo[2001][2001];
string s1, s2;

int dp(int pos1, int pos2)
{
    if (pos1 == n || pos2 == m) return 0;
    if (memo[pos1][pos2] != -1) return memo[pos1][pos2];

    if (s1[pos1] == s2[pos2]) return memo[pos1][pos2] = value[s1[pos1] - 'a'] + dp(pos1 + 1, pos2 + 1);
    else return memo[pos1][pos2] = max(dp(pos1, pos2 + 1), dp(pos1 + 1, pos2));
}

void init()
{
    memset(memo, -1, sizeof(memo));
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 0; i < sz; i++) cin >> value[i];
    cin >> s1 >> s2;

    init();
    cout << dp(0, 0) << endl;
    return 0;
}