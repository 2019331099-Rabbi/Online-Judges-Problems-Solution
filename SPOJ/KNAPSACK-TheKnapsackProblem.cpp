#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 2001
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int n, w, profit[sz], weight[sz], memo[sz][sz];
/**
Problem Link: https://www.spoj.com/problems/KNAPSACK/
*/

void init()
{
    memset(memo, -1, sizeof(memo));
}

int knapsack(int pos, int amount)
{
    if (pos == n) return 0;
    if (memo[pos][amount] != -1) return memo[pos][amount];

    int val1, val2 = 0;
    val1 = knapsack(pos + 1, amount);
    if (amount - weight[pos] >= 0) val2 = profit[pos] + knapsack(pos + 1, amount - weight[pos]);
    return memo[pos][amount] = max(val1, val2);
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();

    cin >> w >> n;
    for (int i = 0; i < n; i++) cin >> weight[i] >> profit[i];
    cout << knapsack(0, w) << endl;
    return 0;
}