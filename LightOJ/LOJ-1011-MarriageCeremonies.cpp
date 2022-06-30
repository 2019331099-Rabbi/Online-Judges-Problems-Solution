#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 16
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
Problem Link: https://lightoj.com/problem/marriage-ceremonies
*/

int marriage[sz][sz], memo[1 << sz];
int n;

int maxIndex(int mask)
{
    int pos = __builtin_popcount(mask);
    if (pos == n) 0;
    if (memo[mask] != -1) return memo[mask];

    int mx = 0;
    for (int i = 0; i < n; i++) {
        if ((1 << i) & mask) continue;
        mx = max(mx, marriage[pos][i] + maxIndex(mask | (1 << i)));
    }
    return memo[mask] = mx;
}

void init()
{
    memset(memo, -1, sizeof(memo));
}

void solve(int i)
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> marriage[i][j];
    }
    init();
    cout << "Case " << i << ": " << maxIndex(0) << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}