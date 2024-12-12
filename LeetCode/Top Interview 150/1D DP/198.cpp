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
    int memo[100];
    Solution() {
        memset(memo, -1, sizeof(memo));
    }

    int maxMoney(vector <int> &nums, int pos) {
        if (pos >= nums.size()) return 0;
        if (memo[pos] != -1) return memo[pos];
        return memo[pos] = max(nums[pos] + maxMoney(nums, pos + 2), maxMoney(nums, pos + 1));
    }

    int rob(vector<int>& nums) {
        return maxMoney(nums, 0);
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    Solution *soln = new Solution();

    vector <int> nums = {2,7,9,3,1};

    cout << soln->rob(nums) << endl;
}