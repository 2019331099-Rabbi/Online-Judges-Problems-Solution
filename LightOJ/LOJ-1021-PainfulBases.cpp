#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 21
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
Problem Link: https://lightoj.com/problem/painful-bases
*/

int base, n, k, memo[1 << 16][sz], number[sz];

int dp(int mask, int remainder)
{
    if (mask == ((1 << n) - 1)) return remainder == 0;
    if (memo[mask][remainder] != -1) return memo[mask][remainder];

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) continue;
        cnt += dp(mask | (1 << i), (remainder * base + number[i]) % k);
    }
    return memo[mask][remainder] = cnt;
}

void init()
{
    memset(memo, -1, sizeof(memo));
}

void solve(int i)
{
    string s;
    cin >> base >> k >> s;
    n = s.size();

    for (int i = 0; i < n; i++) number[i] = (s[i] >= '0' && s[i] <= '9')?(s[i] - '0'):(s[i] - 'A' + 10);
    
    init();
    cout << "Case " << i << ": " << dp(0, 0) << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}