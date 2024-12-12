#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;


// vector <int> solve(vector<int>& nums, int target)
// {
//     vector <pair <int, int>> v;
//     for (int i = 0; i < nums.size(); i++) v.push_back({nums[i], i});
//     sort(v.begin(), v.end());

//     int i = 0, j = v.size();

//     while (i < j) {
//         int sum = v[i].first + v[j].first;
//         if (sum == target) break;
//         else if (sum > target) j--;
//         else i++;
//     }
//     return vector <int> {v[i].second, v[j].second};
// }

vector <int> twoSum(vector<int>& nums, int target)
{
    unordered_map <int, int> ump;

    for (int i = 0; i < nums.size(); i++) {
        int val = target - nums[i];
        if (ump.find(val) != ump.end()) return {ump[val], i};
        ump[nums[i]] = i;
    }
    return {};
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n, target;
    vector <int> v;

    cin >> n >> target;
    while (n--) {
        int val;
        cin >> val;
        v.push_back(val);
    }

    vector <int> ans;
    ans = twoSum(v, target);

    for (auto xx: ans) cout << xx << ' ';
    cout << endl;

    return 0;
}