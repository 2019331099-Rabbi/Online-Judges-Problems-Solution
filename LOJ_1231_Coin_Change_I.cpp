#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 51
#define inf 1e9 + 9
#define mod 100000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
Problem Link: https://lightoj.com/problem/coin-change-i
*/

int n, w, coin[sz], freq[sz];
int64_t memo[sz][1001];

void init()
{
    memset(memo, -1, sizeof(memo));
}

int64_t coinChange(int pos, int amount)
{
    if (pos == n) return amount == 0;
    if (amount == 0) return 1;
    if (memo[pos][amount] != -1) return memo[pos][amount];

    int64_t val = 0;
    val = (val + coinChange(pos + 1, amount)) % mod;
    int sum = 0;
    for (int i = 0; i < freq[pos]; i++) {
        sum += coin[pos];
        if (amount - sum >= 0) val = (val + coinChange(pos + 1, amount - sum)) % mod;
    }
    return memo[pos][amount] = val;
}

void solve(int i)
{
    cin >> n >> w;
    for (int i = 0; i < n; i++) cin >> coin[i];
    for (int i = 0; i < n; i++) cin >> freq[i];

    init();
    cout << "Case " << i << ": " << coinChange(0, w) << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}