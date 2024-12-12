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
Tutorial: https://youtu.be/-uQGzhYj8BQ?si=DjWijUQxlrhHgH8O
*/

/*
Recursive Dynamic Programming Approach:
*/
// class Solution {
// public:
//     int dp(int pos, int buy, int capacity, vector <int> &prices, vector <vector <vector <int>>> &memo) {
//         if (pos == prices.size()) return 0;
//         if (capacity == 0) return 0;
//         if (memo[pos][buy][capacity] != -1) return memo[pos][buy][capacity];

//         int profit;
//         if (buy) {
//             int buying = -prices[pos] + dp(pos + 1, 0, capacity, prices, memo);
//             int exceptBuying = dp(pos + 1, 1, capacity, prices, memo);
//             profit = max(buying, exceptBuying);
//         }
//         else {
//             int selling = prices[pos] + dp(pos + 1, 1, capacity - 1, prices, memo);
//             int exceptSelling = dp(pos + 1, 0, capacity, prices, memo);
//             profit = max(selling, exceptSelling);
//         }
//         return memo[pos][buy][capacity] = profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         vector <vector <vector <int>>> memo(prices.size(), vector <vector <int>>(2, vector <int>(3, -1)));
//         return dp(0, 1, 2, prices, memo);
//     }
// };

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector <vector <vector <int>>> memo(n + 1, vector <vector <int>>(2, vector <int>(3)));

//         // Step 1: Write the base condition
//         for (int pos = 0; pos < n; pos++) {
//             for (int buy = 0; buy <= 1; buy++) memo[pos][buy][0] = 0;
//         }
//         for (int buy = 0; buy <= 1; buy++) {
//             for (int capacity = 0; capacity <= 2; capacity++) memo[n][buy][capacity] = 0;
//         }

//         // Write the recurrence relation
//         for (int pos = n - 1; pos >= 0; pos--) {
//             for (int buy = 0; buy <= 1; buy++) {
//                 for (int capacity = 1; capacity <= 2; capacity++) {
//                     int profit;
//                     if (buy) {
//                         int buying = -prices[pos] + memo[pos + 1][0][capacity];
//                         int exceptBuying = memo[pos + 1][1][capacity];
//                         profit = max(buying, exceptBuying);
//                     }
//                     else {
//                         int selling = prices[pos] + memo[pos + 1][1][capacity - 1];
//                         int exceptSelling = memo[pos + 1][0][capacity];
//                         profit = max(selling, exceptSelling);
//                     }
//                     memo[pos][buy][capacity] = profit;
//                 }
//             }
//         }
//         // return the calling functiion during recursive function call
//         return memo[0][1][2];
//     }
// };

/*
Memory efficient DP
*/
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector <vector <int>> after(2, vector <int>(3));

//         // Step 1: Write the base condition
//         for (int pos = 0; pos < n; pos++) {
//             for (int buy = 0; buy <= 1; buy++) after[buy][0] = 0;
//         }
//         for (int buy = 0; buy <= 1; buy++) {
//             for (int capacity = 0; capacity <= 2; capacity++) after[buy][capacity] = 0;
//         }

//         // Write the recurrence relation
//         for (int pos = n - 1; pos >= 0; pos--) {
//             for (int buy = 0; buy <= 1; buy++) {
//                 for (int capacity = 1; capacity <= 2; capacity++) {
//                     int profit;
//                     if (buy) {
//                         int buying = -prices[pos] + after[0][capacity];
//                         int exceptBuying = after[1][capacity];
//                         profit = max(buying, exceptBuying);
//                     }
//                     else {
//                         int selling = prices[pos] + after[1][capacity - 1];
//                         int exceptSelling = after[0][capacity];
//                         profit = max(selling, exceptSelling);
//                     }
//                     after[buy][capacity] = profit;
//                 }
//             }
//         }
//         // return the calling functiion during recursive function call
//         return after[1][2];
//     }
// };

/*
Alternative Recursive solution:
-------------------------------
2 transaction: B = Buy, S = Sell
              B S B S -> two transactions total. (B, S) -> one transaction
transactions: 0 1 2 3
if transactions is even (0, 2), we can buy stock
if transactions is odd (1, 3), we can sell stock
if two transactions is completed (4), we return 0
*/
class Solution {
public:
    int dp(int pos, int transactions, vector <int> &prices, vector <vector <int>> &memo) {
        if (pos == prices.size() || transactions == 4) return 0;
        if (memo[pos][transactions] != -1) return memo[pos][transactions];

        int profit;
        if (transactions % 2 == 0) {
            int buying = -prices[pos] + dp(pos + 1, transactions + 1, prices, memo);
            int exceptBuying = dp(pos + 1, transactions, prices, memo);
            profit = max(buying, exceptBuying);
        }
        else {
            int selling = prices[pos] + dp(pos + 1, transactions + 1, prices, memo);
            int exceptSelling = dp(pos + 1, transactions, prices, memo);
            profit = max(selling, exceptSelling);
        }
        return memo[pos][transactions] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector <vector <int>> memo(prices.size(), vector <int>(4, -1));
        return dp(0, 0, prices, memo);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector <vector <int>> memo(n + 1, vector <int>(5));

        // Base cases
        for (int transactions = 0; transactions < 4; transactions++) memo[n][transactions] = 0;
        for (int pos = 0; pos < n; pos++) memo[pos][4] = 0;

        for (int pos = n - 1; pos >= 0; pos--) {
            for (int transactions = 0; transactions < 4; transactions++) {
                int profit;
                if (transactions % 2 == 0) {
                    int buying = -prices[pos] + memo[pos + 1][transactions + 1];
                    int exceptBuying = memo[pos + 1][transactions];
                    profit = max(buying, exceptBuying);
                }
                else {
                    int selling = prices[pos] + memo[pos + 1][transactions + 1];
                    int exceptSelling = memo[pos + 1][transactions];
                    profit = max(selling, exceptSelling);
                }
                memo[pos][transactions] = profit;
            }
        }
        return memo[0][0];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector <int> after(5);

        // Base cases
        for (int transactions = 0; transactions < 4; transactions++) after[transactions] = 0;

        for (int pos = n - 1; pos >= 0; pos--) {
            for (int transactions = 0; transactions < 4; transactions++) {
                int profit;
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

    vector <int> prices = {3,3,5,0,0,3,1,4};
    cout << soln->maxProfit(prices) << endl;
}