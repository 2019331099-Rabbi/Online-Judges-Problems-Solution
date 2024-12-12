#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 10000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/*
https://www.youtube.com/watch?v=JDOXKqF60RQ&ab_channel=takeUforward
*/

void nextPermutation(vector<int>& nums)
{
    int pos1 = nums.size() - 2;
    while (pos1 >= 0) {
        if (nums[pos1] < nums[pos1 + 1]) break;
        pos1--;
    }
    int mn = inf, pos2;
    if (~pos1) {
        for (int i = pos1 + 1; i < nums.size(); i++) {
        if ((nums[i] > nums[pos1]) && (nums[i] < mn))
            mn = nums[i], pos2 = i;
        }
        swap(nums[pos1], nums[pos2]);
    }
    sort(nums.begin() + pos1 + 1, nums.end());
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    vector <int> nums;
    int n;

    cin >> n;
    while (n--) {
        int val;
        cin >> val;
        nums.push_back(val);
    }
    nextPermutation(nums);

    for (auto xx: nums) cout << xx << ' ';
    cout << endl;

    return 0;
}