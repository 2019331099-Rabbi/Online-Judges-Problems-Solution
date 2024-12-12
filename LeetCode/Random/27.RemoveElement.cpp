#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int removeElement(vector<int>& nums, int val)
{
    short int top = 0;
    for (short int i = 0; i < nums.size(); i++) {
        if (nums[i] == val) continue;
        nums[top++] = nums[i];
    }
    return top;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector <int> v;

    while (n--) {
        int val;
        cin >> val;
        v.push_back(val);
    }

    cout << removeElement(v, k) << endl;
    return 0;
}