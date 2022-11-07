#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 101
#define inf 100000000
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int64_t row4[]={0, 1, 0, -1};
// int64_t col4[]={1, 0, -1, 0};
 
//int64_t row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int64_t col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int64_t rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int64_t colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

void solve()
{
    int64_t n, k;

    cin >> n >> k;
    set <int64_t> st;
    bool vis[2 * n + 1] = {false};
    int64_t mx = -inf;
    for (int64_t i = 0; i < n; i++) {
        int64_t val;
        cin >> val;
        vis[val] = true;
        mx = max(mx, val);
    }
    // cout << mx << endl;
    // for (auto xx: st) cout << xx << ' ';
    // cout << endl;
    for (int64_t i = 1; i <= 2 * n; i++) if (!vis[i]) st.insert(i);

    int64_t ans = 0;
    while (k--) {
        int64_t val = *st.begin();
        if (val < mx) {
            ans += (mx - val);
            st.erase(val);
        }
        else {
            val = *(--st.end());
            mx = val;
            st.erase(val);
        }
        // cout << ans << endl;
        n++;
        for (int64_t i = 2 * (n - 1) + 1; i <= n * 2; i++) st.insert(i);
        // for (auto xx: st) cout << xx << ' ';
        // cout << endl;
    }
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