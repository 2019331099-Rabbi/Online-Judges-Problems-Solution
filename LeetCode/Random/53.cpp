#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST 
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

int maxSubArray(vector<int>& nums)
{
    int res = INT32_MIN, tmp = 0;

    for (auto xx: nums) {
        tmp = max(tmp + xx, xx);
        res = max(res, tmp);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector <int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout << maxSubArray(nums) << endl;
    return 0;
}