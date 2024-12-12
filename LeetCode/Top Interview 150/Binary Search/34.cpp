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
    int lowerBound(vector <int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (target <= nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }

    int upperBound(vector <int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (target >= nums[mid]) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        int left = lowerBound(nums, target);
        if (left >= nums.size() || nums[left] != target) return {-1, -1};
        int right = upperBound(nums, target);
        return {left, right-1};
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <int> nums = {2, 2};
    int target = 3;
    vector <int> range = soln->searchRange(nums, target);
    cout << range[0] << ' ' << range[1] << endl;
    return 0;
}