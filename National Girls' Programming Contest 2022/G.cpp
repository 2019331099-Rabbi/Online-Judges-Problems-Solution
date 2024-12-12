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
    int n, k;
    cin >> n >> k;

    int ans;
    if (k == 1) ans = n;
    else {
        ans = (n / k) * 2;
        if (n % k) ans++;
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