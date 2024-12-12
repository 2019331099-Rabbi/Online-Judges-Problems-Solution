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
//     int lengthOfLIS(vector<int>& nums) {
//         int len = nums.size();
//         vector <int> lis(len, 1);

//         for (int i = 1; i < len; i++) {
//             for (int j = 0; j < i; j++) {
//                 if (nums[j] < nums[i]) lis[i] = max(lis[i], lis[j] + 1);
//             } 
//         }
//         return *max_element(lis.begin(), lis.end());
//     }
// };

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector <int> sub;
        for (auto &num: nums) {
            if (sub.empty() || sub[sub.size() - 1] < num) sub.push_back(num);
            else {
                auto it = lower_bound(sub.begin(), sub.end(), num); // Find the index of the first element >= num
                *it = num; // Replace that number with num
            }
        }
        return sub.size();
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    Solution *soln = new Solution();

    vector <int> nums = {10,9,2,5,3,7,101,18};
    cout << soln->lengthOfLIS(nums) << endl;
    return 0;
}