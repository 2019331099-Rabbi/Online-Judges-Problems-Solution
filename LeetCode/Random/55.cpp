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
//     bool canJump(vector<int>& nums) {
//         int curr = nums.size() - 1;

//         for (int i = nums.size() - 2; i >= 0; i--) {
//             if (curr - i <= nums[i]) curr = i;
//         }
//         return curr == 0;
//     }
// };

//Peak Valley Approach
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (reachable < i) return false;
            reachable = max(reachable, i + nums[i]);
        }
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <int> nums = {2,1,1,0,4};
    cout << soln->canJump(nums) << endl;


    return 0;

}