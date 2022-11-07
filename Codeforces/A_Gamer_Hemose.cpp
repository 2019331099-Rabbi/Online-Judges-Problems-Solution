#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve()
{
    int n, h;

    cin >> n >> h;
    vector <int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int a = v[n - 1] + v[n - 2];
    int val = h / a;

    if (h % a == 0) cout << 2 * val << endl;
    else if (h % a <= v[n - 1]) cout << 2 * val + 1 << endl;
    else cout << 2 * val + 2 << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}