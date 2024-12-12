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
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        vector <string> ans;

        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            while (j < len && int64_t(nums[j]) - int64_t(nums[j-1]) == int64_t(1)) j++;
            j--;
            string rangeStr = to_string(nums[i]);
            if (j > i) rangeStr += "->", rangeStr += to_string(nums[j]);
            i = j;
            ans.push_back(rangeStr);
        }
        return ans;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution *soln = new Solution();

    vector <int> nums = {2147483647, -2};

    vector <string> results = soln->summaryRanges(nums);
    for (auto xx: results) cout << xx << endl;



}