#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1001
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST 
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

// class Solution {
// public:
//     int memo[13][10002];
//     Solution() {
//         memset(memo, -1, sizeof(memo));
//     }

//     int dp(int pos, int amount, vector <int> &coins) {
//         if (amount < 0) return inf;
//         if (pos == coins.size()) {
//             if (amount == 0) return 0;
//             else return inf;
//         }
        
//         int cnt1 = dp(pos + 1, amount, coins);
//         int cnt2 = 1 + dp(pos, amount - coins[pos], coins);
//         return min(cnt1, cnt2);
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         int res = dp(0, amount, coins);
//         if (res >= sz) return -1;
//         return res;
//     }
// };

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector <int> memo(amount + 1, INT32_MAX);
        memo[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (auto &coin: coins) {
                if (coin <= i && memo[i - coin] != INT32_MAX) {
                    memo[i] = min(memo[i], 1 + memo[i - coin]);
                }
            }
        }
        if (memo[amount] == INT32_MAX) return -1;
        return memo[amount];
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    Solution *soln = new Solution();

    vector <int> coins = {1, 5, 6, 9};
    int amout = 11;
    cout << soln->coinChange(coins, amout) << endl;
}