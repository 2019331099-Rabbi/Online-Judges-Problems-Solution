#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200
#define inf 1000000000000000000
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve()
{
    int n;

    cin >> n;
    vector <int64_t> v(n + 2);
    v[0] = 0, v[n + 1] = 0;
    for (int i = 1; i <= n; i++) cin >> v[i];

    int64_t mx = -inf, mn = inf;
    for (int i = 1; i <= n; i++) {
        if (v[i] == -1) continue;
        if (v[i - 1] == -1 || v[i + 1] == -1) mx = max(mx, v[i]), mn = min(mn, v[i]);
    }
    int64_t ans = (mx + mn) >> 1;
    mx = -inf;
    for (int i = 2; i <= n; i++) {
        int64_t a = (v[i - 1] == -1)?ans:v[i - 1];
        int64_t b = (v[i] == -1)?ans:v[i];
        mx = max(mx, abs(a - b));
    }
    cout << mx << ' ' << ans << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}