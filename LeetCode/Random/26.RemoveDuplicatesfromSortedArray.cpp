#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int top = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[top]) continue;
        nums[++top] = nums[i];
    }
    return top + 1;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    int n;
    vector <int> v;

    cin >> n;
    while (n--) {
        int val;
        cin >> val;
        v.push_back(val);
    }
    cout << removeDuplicates(v) << endl;

    return 0;
}