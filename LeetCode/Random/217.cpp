#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

bool containsDuplicate(vector<int>& nums)
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    unordered_set <int> ust;
    for (auto xx: nums) {
        if (ust.find(xx) != ust.end()) return true;
        ust.insert(xx);
    }
    return false;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    vector <int> nums = {1,1,1,3,3,4,3,2,4,2};

    cout << containsDuplicate(nums) << endl;
    return 0;
}