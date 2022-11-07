#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 20010
#define inf 1000000000
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int w, n, coins[101];

int memo[101][sz];

int minAmount(int pos, int amount)
{
    
}

void init()
{
    memset(memo, -1, sizeof(memo));
}


int minCount(int pos, int amount)
{
    if (amount == 0) {
        return 0;
    }
    if (pos == n) return inf;
    if (memo[pos][amount] != -1) return memo[pos][amount];

    int val;
    val = minCount(pos + 1, amount);
    if (amount - coins[pos] >= 0) val = min(val, 1 + minCount(pos, amount - coins[pos]));
    return memo[pos][amount] = val;
}

void solve()
{
    cin >> w >> n;
    for (int i = 0; i < n; i++) cin >> coins[i];
    
    init();
    int pay = minAmount(0, 0);
    cout << pay << endl;
    init();
    int cnt = minCount(0, pay);
    cout << pay << ' ' << cnt << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}