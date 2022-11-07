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
    int64_t n, k, b, s;

    cin >> n >> k >> b >> s;
    int64_t mn = k * b;
    int64_t mx = mn + (n - 1) * (k - 1) + k - 1;

    if (s > mx || s < mn) cout << -1 << endl;
    else {
        vector <int64_t> ans(n, 0);
        ans[0] = k * b;
        s -= ans[0];

        int i = 1;
        while (i < n && s > 0) {
            ans[i++] = (s - (k - 1) < 0)?s:(k - 1);
            s -= (k - 1);
        }
        if (s > 0) ans[0] += s;
        for (auto xx: ans) cout << xx << ' ';
        cout << endl;
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