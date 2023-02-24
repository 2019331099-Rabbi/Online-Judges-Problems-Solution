#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 55
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row4[]={0, 1, 0, -1};
// int col4[]={1, 0, -1, 0};
 
//int row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

int memo[sz][sz], arr[sz];

void init()
{
    memset(memo, -1, sizeof(memo));
}

int minCost(int l, int r)
{
    if (memo[l][r] != -1) return memo[l][r];
    if (l + 1 == r) return memo[l][r] = 0;

    int mn = INT32_MAX;
    for (int i = l + 1; i < r; i++) {
        mn = min(mn, minCost(l, i) + minCost(i, r) + arr[r] - arr[l]);
    }
    return memo[l][r] = mn;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int len;
    while (cin >> len && len) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        arr[0] = 0, arr[n + 1] = len;

        init();
        cout << "The minimum cutting is " << minCost(0, n + 1) << '.' << endl;
    }
    return 0;
}