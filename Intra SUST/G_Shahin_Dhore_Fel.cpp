#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve()
{
    int s, a, b;

    cin >> s >> a >> b;

    if (s == 0) {
        cout << 0 << endl;
        return;
    }

    if (a <= b) {
        cout << -1 << endl;
        return;
    }

    cout << fixed;

    double ans = (double)s / (double)(a - b);
    cout << setprecision(6) << ans << endl;

}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}