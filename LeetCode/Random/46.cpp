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

vector <vector <int>> result;
vector <bool> vis(6);

void solve(vector<int>nums, int i, vector<vector<int>>&ans)
{
    cout << i << endl;
    for (auto xx: nums) cout << xx << ' ';
    cout << endl << endl;
    if(i == nums.size()) {
        ans.push_back(nums);
        return;
    }

    for(int j = i; j < nums.size(); j++) {
        swap(nums[i], nums[j]);
        solve(nums, i+1, ans);
        swap(nums[i], nums[j]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>>ans;
    solve(nums, 0, ans);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    vector <int> nums = {1, 2, 3};

    auto result = permute(nums);
    for (int i = 0; i < result.size(); i++) {
        for (auto xx: result[i]) cout << xx << ' ';
        cout << endl;
    }

}