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
        int top = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[top] == nums[i]) continue;
            nums[++top] = nums[i];
        }
        return top + 1;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <int> nums = {1, 2};
    int val = 2;

    cout << soln->removeDuplicates(nums);


}