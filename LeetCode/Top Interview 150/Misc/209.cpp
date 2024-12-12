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
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int left = 0, right = 0, len = nums.size();
        int ans = INT32_MAX;

        while (right < len) {
            sum += nums[right];
            if (sum >= target) {
                while (sum >= target) {
                    sum -= nums[left];
                    left++;
                }
                ans = min(ans, right - left + 2);
            }
            right++;
        }
        return (ans == INT32_MAX)?0:ans;
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    Solution *soln = new Solution();

    int target = 7;
    vector <int> nums = {2, 3, 4, 1, 2, 3};

    cout << soln->minSubArrayLen(target, nums) << endl;
}