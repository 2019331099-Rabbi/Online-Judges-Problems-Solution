#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
int col[] = {1, -1, 0, 0, -1, 1, 1, -1};


int searchInsert(vector<int>& nums, int target)
{
    auto it = lower_bound(nums.begin(), nums.end(), target);
    return distance(nums.begin(), it);
}

int lowerBound(vector<int>& nums, int target)
{
    int i = 0, j = nums.size() - 1;

    int ans = -1;
    while (i <= j) {
        int mid = (i + j) >> 1;
        if (target >= nums[mid]) ans = mid, i = mid + 1;
        else j = mid - 1;
    }
    if (ans < 0) return ans + 1;
    return (nums[ans] == target)?ans:ans+1;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    vector<int> nums = {1,3,5,6};
    int target = 0;

    cout << searchInsert(nums, target) << endl;

    cout << lowerBound(nums, target) << endl;
}