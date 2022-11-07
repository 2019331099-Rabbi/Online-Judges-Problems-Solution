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
    int n, k;

    cin >> n >> k;
    if (k < n) cout << "No" << endl;
    else if (k % n == 0) {
        cout << "Yes" << endl;
        int tmp = k / n;
        for (int i = 0; i < n; i++) cout << tmp << ' ';
        cout << endl;
    }
    else if (!(n & 1) && (k & 1)) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        if (n & 1) {
            for (int i = 1; i < n; i++) cout << 1 << ' ';
            cout << k - (n - 1) << endl;
        }
        else {
            int tmp = (k - (n - 2)) / 2;
            cout << tmp << ' ' << tmp;
            for (int i = 2; i < n; i++) cout << ' ' << 1;
            cout << endl;
        }
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}