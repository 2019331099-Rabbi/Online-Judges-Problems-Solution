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
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        unordered_set <int> ust(nums.begin(), nums.end()), vis;

        int mx = 0;
        for (auto &val: nums) {
            if (ust.find(val) != ust.end()) {
                int cnt = 1;
                int x = val;
                while (ust.find(++x) != ust.end()) cnt++, ust.erase(x);
                x = val;
                while (ust.find(--x) != ust.end()) cnt++, ust.erase(x);
                mx = max(mx, cnt);
            }
        }
        return mx;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution *soln = new Solution();

    vector <int> nums = {0,3,7,2,5,8,4,6,0,1};
    cout << soln->longestConsecutive(nums) << endl;
    return 0;


}