#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve()
{
    int n;

    cin >> n;
    vector <int64_t> v(n), cumsum(n);
    for (auto &xx: v) cin >> xx;
    
    sort(v.begin(), v.end());
    cumsum[0] = v[0];
    for (int i = 1; i < n; i++) cumsum[i] = cumsum[i - 1] + v[i];

    // for (auto xx: v) cout << xx << ' ';
    // cout << endl;
    // for (auto xx: cumsum) cout << xx << ' ';
    // cout << endl;

    int64_t mn = INT64_MAX;
    for (int i = 0; i < n; i++) {
        int64_t val = v[i];
        int64_t tmp1 = val * (i + 1) - cumsum[i];
        int64_t tmp2 = (cumsum[n - 1] - cumsum[i]) - val * (n - i - 1);
        mn = min(mn, tmp1 + tmp2);
    }
    cout << mn << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}