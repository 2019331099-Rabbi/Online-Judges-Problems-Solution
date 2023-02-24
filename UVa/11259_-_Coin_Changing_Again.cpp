#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 5
#define inf 1e9 + 9
#define mod 100000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int64_t n = 4, w, coin[sz], freq[sz], memo[sz][100010];

void init()
{
    memset(memo, -1, sizeof(memo));
}

int64_t coinChange(int pos, int64_t amount)
{
    if (pos == n) return amount == 0;
    if (amount == 0) return 1;
    if (memo[pos][amount] != -1) return memo[pos][amount];

    int64_t val = coinChange(pos + 1, amount);
    int64_t sum = 0;
    for (int i = 0; i < freq[pos]; i++) {
        sum += coin[pos];
        if (amount - sum >= 0) val += coinChange(pos + 1, amount - sum);
    }
    return memo[pos][amount] = val;
}

void solve()
{
    cin >> coin[0] >> coin[1] >> coin[2] >> coin[3];
    
    int q;
    cin >> q;
    while (q--) {
        cin >> freq[0] >> freq[1] >> freq[2] >> freq[3];
        cin >> w;
        cout << coinChange(0, w) << endl;
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}