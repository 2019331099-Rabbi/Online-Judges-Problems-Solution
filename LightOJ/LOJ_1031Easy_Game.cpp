#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 101
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
Problem Link: https://lightoj.com/problem/easy-game
*/

int memo[sz][sz][2], arr[sz];

void init()
{
    memset(memo, -1, sizeof(memo));
}

int dp(int left, int right, int flag)
{
    if (left > right) return 0;
    if (memo[left][right][flag] != -1) return memo[left][right][flag];

    if (flag) {
        int sum = 0, ans = INT_MIN;
        for (int i = left; i <= right; i++) {
            sum += arr[i];
            ans = max(ans, sum + dp(i + 1, right, 0));
        }
        sum = 0;
        for (int i = right; i >= left; i--) {
            sum += arr[i];
            ans = max(ans, sum + dp(left, i - 1, 0));
        }
        return memo[left][right][flag] = ans;
    }
    else {
        int sum = 0, ans = INT_MAX;
        for (int i = left; i <= right; i++) {
            sum -= arr[i];
            ans = min(ans, sum + dp(i + 1, right, 1));
        }
        sum = 0;
        for (int i = right; i >= left; i--) {
            sum -= arr[i];
            ans = min(ans, sum + dp(left, i - 1, 1));
        }
        return memo[left][right][flag] = ans;
    }
}

void solve(int i)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    init();
    cout << "Case " << i << ": " << dp(0, n - 1, 1) << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}