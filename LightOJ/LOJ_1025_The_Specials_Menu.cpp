#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 61
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
Problem Link: https://lightoj.com/problem/the-specials-menu
*/

int64_t memo[sz][sz];
int len;
string s;

int64_t dp(int left, int right)
{
    if (left == right) return 1;
    if (left > right) return 0;
    if (memo[left][right] != -1) return memo[left][right];

    int64_t val;
    if (s[left] == s[right]) val = 1 + dp(left + 1, right) + dp(left, right - 1);
    else val = dp(left + 1, right) + dp(left, right - 1) - dp(left + 1, right - 1);
    return memo[left][right] = val;
}

void init()
{
    memset(memo, -1, sizeof(memo));
}

void solve(int i)
{
    cin >> s;
    len = s.size();
    init();
    cout << "Case " << i << ": " << dp(0, len - 1) << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}