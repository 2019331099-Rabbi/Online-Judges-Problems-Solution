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
    int removeDuplicates(vector<int>& nums) {
        nums.push_back(100001);
        int left = 0, pos = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[left] != nums[right]) {
                nums[pos++] = nums[left];
                if (right - left > 1) nums[pos++] = nums[left];
                left = right;
            }
        }
        return pos;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <int> nums = {0, 0, 0, 0, 1, 1, 1, 2, 3, 3, 3};

    cout << soln->removeDuplicates(nums);


}