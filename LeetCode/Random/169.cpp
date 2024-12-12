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
    int majorityElement(vector<int>& nums) {
        int element = 0;
        int count = 0;
        for (auto xx: nums) {
            if (count == 0) element = xx;
            if (element == xx) count++;
            else count--;
        }
        return element;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <int> nums = {6,5,5};
    cout << soln->majorityElement(nums) << endl;


}