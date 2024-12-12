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
    int64_t a, b;

    cin >> a >> b;
    int64_t ans = a + b + 1;
    if (ans >= 1000000000) ans = 0;
    cout << ans << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    T = 1;
    while (T--) solve();
    return 0;
}