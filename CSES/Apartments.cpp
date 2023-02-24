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
    int n, m, k;

    cin >> n >> m >> k;
    vector <int> des(n), gib(m);

    for (auto &xx: des) cin >> xx;
    for (auto &xx: gib) cin >> xx;
    sort(des.begin(), des.end());
    sort(gib.begin(), gib.end());

    int ans = 0, i = 0, j = 0;

    while (i < n && j < m) {
        if (abs(des[i] - gib[j]) <= k) ans++, i++, j++;
        else {
            if (des[i] - gib[j] > k) j++;
            else i++;
        }
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