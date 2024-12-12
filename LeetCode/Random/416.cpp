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
    vector <vector <int>> memo;
    bool isPossible(int pos, int sum, vector <int> &nums) {
        if (sum < 0) return false;
        if (pos == nums.size()) return sum == 0;

        if (memo[pos][sum] != -1) return memo[pos][sum];
        return memo[pos][sum] = isPossible(pos + 1, sum - nums[pos], nums) || isPossible(pos + 1, sum, nums);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto xx: nums) sum += xx;
        if (sum & 1) return false;

        sum = sum / 2;
        memo = vector<vector<int>>(nums.size(), vector<int>(sum+1, -1));
        return isPossible(0, sum, nums);
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    Solution *soln = new Solution();

    vector <int> nums = {1, 5, 11, 9};
    cout << soln->canPartition(nums) << endl;

    return 0;
}