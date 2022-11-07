#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200
#define inf 1e18
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve()
{
    int64_t n;

    cin >> n;
    int64_t a[n], b[n];

    for (int64_t i = 0; i < n; i++) cin >> a[i];
    for (int64_t i = 0; i < n; i++) cin >> b[i];


    int64_t mn1, mn2, mn3, mn4;
    mn1 = mn2 = mn3 = mn4 = inf;
    for (int64_t i = 0; i < n; i++) mn1 = min(mn1, abs(a[0] - b[i]));
    for (int64_t i = 0; i < n; i++) mn2 = min(mn2, abs(a[n - 1] - b[i]));
    for (int64_t i = 0; i < n; i++) mn3 = min(mn3, abs(b[0] - a[i]));
    for (int64_t i = 0; i < n; i++) mn4 = min(mn4, abs(b[n - 1] - a[i]));

    int64_t ans = inf;
    ans = min(ans, abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]));
    ans = min(ans, abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]));

    ans = min(ans, abs(a[0] - b[0]) + mn2 + mn4);
    ans = min(ans, abs(a[n - 1] - b[n - 1]) + mn1 + mn3);
    ans = min(ans, abs(a[0] - b[n - 1]) + mn2 + mn3);
    ans = min(ans, abs(a[n - 1] - b[0]) + mn1 + mn4);

    ans = min(ans, mn1 + mn2 + mn3 + mn4);

    cout << ans << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}