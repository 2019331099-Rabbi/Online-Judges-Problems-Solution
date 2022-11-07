#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve()
{
    int n;
    cin >> n;

    cout << 2 << endl;
    bool vis[n + 1] = {false};

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        for (int j = i; j <= n; j *= 2) {
            cout << j << ' ';
            vis[j] = true;
        }
    }
    cout << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}