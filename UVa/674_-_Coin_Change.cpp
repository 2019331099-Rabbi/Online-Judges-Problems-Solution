#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 5
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int coins[] = {1, 5, 10, 25, 50};
int n, memo[sz][7500];

int coinChange(int pos, int amount)
{
    if (pos == sz) return amount == 0;
    if (amount == 0) return 1;
    if (memo[pos][amount] != -1) return memo[pos][amount];

    int ans = 0;
    ans += coinChange(pos + 1, amount);
    if (amount - coins[pos] >= 0) ans += coinChange(pos, amount - coins[pos]);
    return memo[pos][amount] = ans;
}

void init()
{
    memset(memo, -1, sizeof(memo));
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();
    while (cin >> n) {
        cout << coinChange(0, n) << endl;
    }
}