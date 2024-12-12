#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST 
using namespace std;

int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

vector<int> productExceptSelf(vector<int>& nums)
{
    int prod = 1, cnt = 0, len = nums.size();

    for (auto xx: nums) {
        if (xx) prod *= xx;
        else cnt++;
    }
    vector <int> result(len);

    if (cnt == 1) {
        for (int i = 0; i < len; i++) result[i] = (nums[i])?0:prod;
        return result;
    }
    if (cnt > 1) {
        for (auto &xx: result) xx = 0;
        return result;
    }
    for (int i = 0; i < nums.size(); i++) result[i] = prod / nums[i];
    return result;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    vector <int> nums = {1, 2, 3, 4};

    vector <int> result = productExceptSelf(nums);

    for (auto xx: result) cout << xx << ' ';
    cout << endl;

    return 0;
}