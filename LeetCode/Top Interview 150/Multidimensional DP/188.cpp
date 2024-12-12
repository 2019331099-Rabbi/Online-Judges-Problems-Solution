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
//     int dp(int pos, int transactions, vector <vector <int>> &memo, vector <int> &prices, int k) {
//         if (pos == prices.size() || transactions == k) return 0;
//         if (memo[pos][transactions] != -1) return memo[pos][transactions];

//         int profit = 0;
//         if (transactions % 2 == 0) {
//             int buying = -prices[pos] + dp(pos + 1, transactions + 1, memo, prices, k);
//             int exceptBuying = dp(pos + 1, transactions, memo, prices, k);
//             profit = max(buying, exceptBuying);
//         }
//         else {
//             int selling = prices[pos] + dp(pos + 1, transactions + 1, memo, prices, k);
//             int exceptSelling = dp(pos + 1, transactions, memo, prices, k);
//             profit = max(selling, exceptSelling);
//         }
//         return memo[pos][transactions] = profit;
//     }
//     int maxProfit(int k, vector<int>& prices) {
//         vector <vector <int>> memo(prices.size(), vector <int>(2*k, -1));
//         return dp(0, 0, memo, prices, 2*k);
//     }
// };

// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         k *= 2;
//         vector <vector <int>> memo(n + 1, vector <int>(k + 1));

//         for (int transactions = 0; transactions < k; transactions++) memo[n][transactions] = 0;
//         for (int pos = 0; pos < pos; pos++) memo[pos][k] = 0;

//         for (int pos = n - 1; pos >= 0; pos--) {
//             for (int transactions = 0; transactions < k; transactions++) {
//                 int profit = 0;
//                 if (transactions % 2 == 0) {
//                     int buying = -prices[pos] + memo[pos + 1][transactions + 1];
//                     int exceptBuying = memo[pos + 1][transactions];
//                     profit = max(buying, exceptBuying);
//                 }
//                 else {
//                     int selling = prices[pos] + memo[pos + 1][transactions + 1];
//                     int exceptSelling = memo[pos + 1][transactions];
//                     profit = max(selling, exceptSelling);
//                 }
//                 memo[pos][transactions] = profit;
//             }
//         }
//         return memo[0][0];
//     }
// };

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        k *= 2;
        vector <int> after(k + 1);

        for (int transactions = 0; transactions < k; transactions++) after[transactions] = 0;
        for (int pos = n - 1; pos >= 0; pos--) {
            for (int transactions = 0; transactions < k; transactions++) {
                int profit = 0;
                if (transactions % 2 == 0) {
                    int buying = -prices[pos] + after[transactions + 1];
                    int exceptBuying = after[transactions];
                    profit = max(buying, exceptBuying);
                }
                else {
                    int selling = prices[pos] + after[transactions + 1];
                    int exceptSelling = after[transactions];
                    profit = max(selling, exceptSelling);
                }
                after[transactions] = profit;
            }
        }
        return after[0];
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <int> prices = {3,2,6,5,0,3};
    int k = 2;
    cout << soln->maxProfit(k, prices) << endl;



}