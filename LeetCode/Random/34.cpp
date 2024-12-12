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

vector <int> searchRange(vector<int>& nums, int target)
{
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (target <= nums[ mid]) r = mid - 1;
        else l = mid + 1;
    }
    if (l == nums.size() || nums[l] != target) return {-1, -1};
    
    vector <int> result = {l};

    l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (target >= nums[mid]) l = mid + 1;
        else r = mid - 1;
    }
    result.push_back(l-1);
    return result;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    vector<int> nums = {5, 7, 8, 8, 8, 10};
    int target = 8;

    auto res = searchRange(nums, target);
    for (auto xx: res) cout << xx << ' ';
    cout << endl;
    return 0;

}