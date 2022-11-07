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
    int n, q;
    cin >> n >> q;
    vector <int64_t> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.rbegin(), v.rend());
    for (int i = 1; i < n; i++) v[i] += v[i - 1];

    while (q--) {
        int64_t sugar;
        cin >> sugar;
        int tmp = lower_bound(v.begin(), v.end(), sugar) - v.begin();
        if (tmp >= n) cout << -1 << endl;
        else cout << tmp + 1 << endl;
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}