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

int search(vector<int>& nums, int target)
{
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = (left + right) >> 1;

        if (target == nums[mid]) return mid;
        else if (target > nums[mid]) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// int search(vector<int>& nums, int target)
// {
//     auto it = lower_bound(nums.begin(), nums.end(), target);
//     if (it != nums.end() && *it == target) return it - nums.begin();
//     return -1;
// }

// int search(vector<int>& nums, int target)
// {
//     int left = 0, right = nums.size() - 1;
//     while (left <= right) {
//         int mid1 = left + (right - left) / 3;
//         int mid2 = right - (right - left) / 3;

//         if (nums[mid1] == target) return mid1;
//         if (nums[mid2] == target) return mid2;

//         if (target < nums[mid1]) right = mid1 - 1;
//         else if (target > nums[mid2]) left = mid2 + 1;
//         else left = mid1 + 1, right = mid2 - 1;
//     }
//     return -1;
// }


int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    vector<int> arr = {-1,0,3,5,9,12};
    int target = 5;

    cout << search(arr, target) << endl;


}