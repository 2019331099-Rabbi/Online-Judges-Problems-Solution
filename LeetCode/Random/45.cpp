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
    int jump(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return 0;
        
        queue <pair <pair <int, int>, int>> q;
        q.push({{0, 0}, 0});

        while (!q.empty()) {
            int left = q.front().first.first;
            int right = q.front().first.second;
            int step = q.front().second;
            q.pop();

            int reachable = 0;
            while (left <= right) {
                reachable = max(reachable, left + nums[left]);
                left++;
            }
            if (reachable >= len - 1) return step + 1;
            q.push({{right, reachable}, step + 1});
        }
        return 0;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <int> nums = {4};
    cout << soln->jump(nums) << endl;
}