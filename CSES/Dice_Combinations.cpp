#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1000010
#define inf 1000000009
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int64_t memo[sz];

void init()
{
    memset(memo, -1, sizeof(memo));
}

int64_t dp(int64_t amount)
{
    if (amount == 0) return 1;
    if (amount < 0) return 0;
    if (memo[amount] != -1) return memo[amount];

    int64_t cnt = 0;
    for (int64_t i = 1; i <= 6; i++) cnt = (cnt + dp(amount - i)) % mod;
    return memo[amount] = cnt;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t amount;
    cin >> amount;
    init();
    cout << dp(amount) << endl;
    return 0;
}