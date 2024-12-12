#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int maxArea(vector<int> &height)
{
    int i = 0, j = height.size() - 1, mx = -1;

    while (i < j)
    {
        int area = min(height[i], height[j]) * (j - i);
        mx = max(mx, area);

        if (height[j] > height[i])
            i++;
        else
            j--;
    }
    return mx;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);
    int n;
    vector<int> height;

    cin >> n;
    while (n--)
    {
        int val;
        cin >> val;
        height.push_back(val);
    }
    cout << maxArea(height) << endl;
}