#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST 
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

void sortColors(vector<int>& nums)
{
    int num0 = 0, num1 = 0;
    for (auto xx: nums) {
        if (xx == 0) num0++;
        else if (xx == 1) num1++;
    }
    int i = 0;
    while (num0--) nums[i++] = 0;
    while (num1--) nums[i++] = 1;
    while (i < nums.size()) nums[i++] = 2;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    vector <int> nums = {2,0,1};

    sortColors(nums);

    for (auto xx: nums) cout << xx << ' ';
    cout << endl;

    return 0;
}