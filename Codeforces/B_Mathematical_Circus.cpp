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
    int n, k;

    cin >> n >> k;
    if (k % 4 == 0) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        if (k & 1) for (int i = 1; i <= n; i += 2) cout << i << ' ' << i + 1 << endl;
        else {
            for (int i = 1; i <= n; i += 2) {
                if (i % 4 == 1) cout << i + 1 << ' ' << i << endl;
                else cout << i << ' ' << i + 1 << endl;
            }
        }
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}