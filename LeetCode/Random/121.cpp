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

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0], profit = 0;
        for (auto xx: prices) mn = min(mn, xx), profit = max(profit, xx - mn);
        return profit;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <int> prices = {7,1,5,3,6,4};
    cout << soln->maxProfit(prices) << endl;
}