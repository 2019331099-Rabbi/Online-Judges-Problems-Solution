#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 150
#define inf 10000000
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int n, w, price[sz], memo[sz][sz];

int minPrice(int pos, int amount)
{
    if (amount == 0) return 0;
    if (pos > n) return inf;
    if (memo[pos][amount] != -1) return memo[pos][amount];

    int val = inf;
    val = min(val, minPrice(pos + 1, amount));
    if (price[pos] != -1 && amount - pos >= 0) val = min(val, price[pos] + minPrice(pos, amount - pos));
    return memo[pos][amount] = val;
}

void init()
{
    memset(memo, -1, sizeof(memo));
}

void solve()
{
    
    cin >> n >> w;
    for (int i = 1; i <= w; i++) cin >> price[i];

    init();
    int ans = minPrice(1, w);
    if (ans >= inf) cout << -1 << endl;
    else cout << ans << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    
    return 0;
}