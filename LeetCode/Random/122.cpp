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
//     int maxProfit(vector<int>& prices) {
//         int mn = prices[0], profit = 0;
//         for (auto xx: prices) {
//             mn = min(mn, xx);
//             if (xx - mn > 0) profit += xx - mn, mn = xx;
//         }
//         return profit;
//     }
// };

/*
Recursive Dynamic Programming Approach:
---------------------------------------

Each index, we have two choice.
    1. Buy the stock
    2. Sell the stock
Again we can not hold two stock together. We have to sell first stock, before buying second stock.
The "buy" keep track of this.
*/
// class Solution {
// public:
//     int dp(int pos, int buy, vector <int> &prices, vector <vector <int>> &memo) {
//         if (pos == prices.size()) return 0;
//         if (memo[pos][buy] != -1) return memo[pos][buy];

//         int profit = 0;
//         if (buy) {
//             int buying = -prices[pos] + dp(pos + 1, 0, prices, memo);
//             int exceptBuying = dp(pos + 1, 1, prices, memo);
//             profit = max(buying, exceptBuying);
//         }
//         else {
//             int selling = prices[pos] + dp(pos + 1, 1, prices, memo);
//             int exceptSelling = dp(pos + 1, 0, prices, memo);
//             profit = max(selling, exceptSelling);
//         }
//         return memo[pos][buy] = profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         vector <vector <int>> memo(prices.size(), vector <int>(2, -1));
//         return dp(0, 1, prices, memo);
//     }
// };

/*
Iterative Dynamic Programming Approach:
---------------------------------------

The is the opposite approach of recursive DP.
Steps:
    1. Write the base cases.
    2. Iterate through the changing parameters.
    3. Write the recurrence relation.

*/

/*
Iterative DP: Memeory optimization
From the recurrance relation, we observe that, when we calculate profit in each iteration
it depends on only its previous state.

memo[pos][buy] depens on
    memo[pos + 1][0]
    memo[pos + 1][1]
We can simply maintain this using only two variable instead of an "memo" array
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector <int> memo(2); // memory optimized memoization. We only need to store the previous state.
        memo[0] = memo[1] = 0;

        for (int pos = n - 1; pos >= 0; pos--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    int buying = -prices[pos] + memo[0];
                    int exceptBuying = memo[1];
                    profit = max(buying, exceptBuying);
                }
                else {
                    int selling = prices[pos] + memo[1];
                    int exceptSelling = memo[0];
                    profit = max(selling, exceptSelling);
                }
                memo[buy] = profit;
            }
        }
        return memo[1];
    }
};



int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <int> prices = {7,1,5,3,6,4};
    cout << soln->maxProfit(prices) << endl;



}