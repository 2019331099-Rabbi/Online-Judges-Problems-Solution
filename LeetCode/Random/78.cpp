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
    vector <vector <int>> allPossibleCom;
    void ncr(vector <int> &order, vector <int> &nums, int curr, int r)
    {
        if (order.size() == r) {
            allPossibleCom.push_back(order);
            return;
        }
        for (int i = curr; i < nums.size(); i++) {
            order.push_back(nums[i]);
            ncr(order, nums, i + 1, r);
            order.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        for (int i = 0; i <= nums.size(); i++) {
            vector <int> order;
            ncr(order, nums, 0, i);
        }
        return allPossibleCom;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <int> nums = {1, 2, 3};
    vector <vector <int>> result = soln->subsets(nums);

    for (int i = 0; i < result.size(); i++) {
        for (auto xx: result[i]) cout << xx << ' ';
        cout << endl;
    }
}