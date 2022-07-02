#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 101
#define inf 1e9 + 9
#define mod 100000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
Problem Link: https://lightoj.com/problem/digit-count
*/

int digits[sz], n, m;
int memo[11][11];

int dp(int cnt, int prev)
{
    if (cnt == n) return 1;
    if (memo[cnt][prev] != -1) return memo[cnt][prev];

    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (abs(prev - digits[i]) <= 2) ans += dp(cnt + 1, digits[i]);
    }
    return memo[cnt][prev] = ans;
}

void init()
{
    memset(memo, -1, sizeof(memo));
}

void solve(int i)
{   
    cin >> m >> n;
    for (int i = 0; i < m; i++) cin >> digits[i];

    init();
    int ans = 0;
    for (int i = 0; i < m; i++) ans += dp(1, digits[i]);
    cout << "Case " << i << ": " << ans << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}