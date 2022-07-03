#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 110
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int a, b, k1, k2, memo[sz][sz][11][11];

void init()
{
    memset(memo, -1, sizeof(memo));
}

int dp(int cnta, int cntb, int sa, int sb)
{
    if (cnta == a && cntb == b) return (sa <= k1 && sb <= k2);
    if (cnta > a || cntb > b || sa > k1 || sb > k2) return 0;
    if (memo[cnta][cntb][sa][sb] != -1) return memo[cnta][cntb][sa][sb];

    int ans = 0;
    ans = (ans + dp(cnta + 1, cntb, sa + 1, 0)) % mod;
    ans = (ans + dp(cnta, cntb + 1, 0, sb + 1)) % mod;
    return memo[cnta][cntb][sa][sb] = ans;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();

    cin >> a >> b >> k1 >> k2;
    cout << dp(0, 0, 0, 0) << endl;
    return 0;
}