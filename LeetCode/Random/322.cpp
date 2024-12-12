#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST 
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

int memo[13][10001];

int DP(int pos, int amount, vector <int> &coins)
{
    if (amount < 0) return inf;
    if (pos == coins.size()) {
        if (amount == 0) return 0;
        else return inf;
    }
    if (memo[pos][amount] != -1) return memo[pos][amount];

    int cnt1 = 1 + DP(pos, amount - coins[pos], coins);
    int cnt2 = DP(pos + 1, amount, coins);
    return memo[pos][amount] = min(cnt1, cnt2);
}

int coinChange(vector<int>& coins, int amount)
{
    memset(memo, -1, sizeof(memo));
    int cnt = DP(0, amount, coins);
    return (cnt == inf)?-1:cnt;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    vector <int> coins = {1,2,5};
    int amount = 11;

    cout << coinChange(coins, amount) << endl;



}