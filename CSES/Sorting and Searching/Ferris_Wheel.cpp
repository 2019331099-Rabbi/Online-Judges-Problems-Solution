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
    int n, w;

    cin >> n >> w;
    vector <int> v(n);
    for (auto &xx: v) cin >> xx;

    sort(v.begin(), v.end());
    // for (auto xx: v) cout << xx << ' ';
    // cout << endl;

    int i = 0, j = n - 1, ans = 0;

    while (i <= j) {
        if (v[i] + v[j] <= w) i++, j--;
        else j--;
        ans++;
    }
    cout << ans << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}