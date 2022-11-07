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
    int n;

    cin >> n;

    if (n & 1) {
        if (n % 3 == 2) for (int i = 1; i <= n; i++) cout << i << ' ';
        else if (n % 3 == 0) {
            cout << 2 << ' ' << 1 << ' ' << 4 << ' ' << 3 << ' ';
            for (int i = 5; i <= n; i++) cout << i << ' ';
        }
        else {
            cout << 2 << ' ' << 1 << ' ';
            for (int i = 3; i <= n - 2; i++) cout << i << ' ';
            cout << n - 1 << ' ' << n;
        }
    }
    else {
        for (int i = n - 2; i >= 1; i--) cout << i << ' ';
        cout << n - 1 << ' ' << n;
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