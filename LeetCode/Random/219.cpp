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

auto init = []() -> int {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map <int, int> ump;

        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            if (ump.find(val) != ump.end() && (i - ump[val]) <= k) return true;
            ump[val] = i;
        }
        return false;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution *soln = new Solution();

    vector <int> nums = {1,2,3,1, 2, 3};
    int k = 2;

    cout << soln->containsNearbyDuplicate(nums, k) << endl;

    return 0;


}