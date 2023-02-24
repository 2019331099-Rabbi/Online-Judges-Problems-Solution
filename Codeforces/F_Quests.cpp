#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 2000000000
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int64_t64_t64_t row4[]={0, 1, 0, -1};
// int64_t64_t64_t col4[]={1, 0, -1, 0};
 
//int64_t64_t64_t row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int64_t64_t64_t col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int64_t64_t64_t rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int64_t64_t64_t colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

void solve()
{
    int64_t n, c, d;

    cin >> n >> c >> d;
    vector <int64_t> v;

    int64_t mx = -inf;
    for (int64_t i = 0; i < n; i++) {
        int64_t val;
        cin >> val;
        v.push_back(val);
        mx = max(mx, val);
    }
    sort(v.rbegin(), v.rend());
    // for (auto xx: v) cout << xx << ' ';
    // cout << endl;

    int64_t tmp = d / 2;
    if (d % 2) tmp++;
    if (v[0] * d < c) {
        cout << "Impossible" << endl;
        return;
    }
    int64_t l = 0, r = 1e18, ans;
    int64_t presum[n];
    for (int64_t i = 0; i < n; i++) presum[i] = v[i];
    for (int64_t i = 1; i < n; i++) presum[i] += presum[i - 1];

    if (presum[min(n - 1, d - 1)] >= c) {
        cout << "Infinity" << endl;
        return;
    }

    // for (int64_t i = 0; i < n; i++) cout << presum[i] << ' ';
    // cout << endl;

    // cout << "lr " << l << ' ' << r << endl << endl;

    if (v[0] * d >= c) ans = 0;
    while (l <= r) {
        int64_t m = (l + r) / 2;
        int64_t tmp = 0;
        
        int64_t val = m + 1;
        if (m < n) {
            tmp = presum[min(n - 1, val - 1)] * (d / val); 
            if (val < d) tmp += presum[min(d % val, n - 1)];
        }
        else {
            val = n + (m + 1 - n);
            // cout << val << endl;
            tmp = presum[n - 1] * (d / val);
            if (val < d) tmp += presum[min(d % val, n - 1)];
        }
        // cout << m << ' ' << tmp << endl;
        if (tmp >= c) l = m + 1, ans = max(ans, m);
        
        else r = m - 1;
    }
    cout << ans << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}