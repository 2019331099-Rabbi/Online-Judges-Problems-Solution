#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 110
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve()
{
    int64_t n, tmp;
    cin >> n;
    int ans = 0;

    while (n > 1) {
        tmp = (-1 + sqrt(1.0 + 24.00 * n)) / 6;
        tmp = (3 * tmp * tmp + tmp) / 2;
        n -= tmp;
        ans ++;
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