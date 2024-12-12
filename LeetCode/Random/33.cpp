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

int search(vector<int>& nums, int target)
{
    int pos = 0;
    for (pos = 1; pos < nums.size(); pos++) {
        if (nums[pos] < nums[pos - 1]) break;
    }
    
    int left = 0, right = pos - 1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) right = mid - 1;
        else left = mid + 1;
    }

    left = pos, right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    vector <int> nums = {0, 1, 2, 3, 4, 5, 6, 7};
    int target = 0;

    cout << search(nums, target) << endl;

    return 0;
}