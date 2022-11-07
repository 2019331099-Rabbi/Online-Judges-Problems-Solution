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
    int64_t n, m, x, y, a, d, t;
    cin >> n >> m >> x >> y;

    a = x - 1;
    d = (n - 1) * 2;
    t = y - 1;
    cout << a << ' ' << d << ' ' << ' ' << t << endl;
    if ((t - a) % d== 0) {
        cout << "BestWishes" << endl;
        return;
    }

    a = (n - x) + (n - 1);
    d = (n - 1) * 2;
    t = y - 1;
    cout << a << ' ' << d << ' ' << ' ' << t << endl;
    if ((t - a) % d== 0) {
        cout << "BestWishes" << endl;
        return;
    }

    a = m - y;
    d = (m - 1) * 2;
    t = m - 1 + x - 1;
    cout << a << ' ' << d << ' ' << ' ' << t << endl;
    if ((t - a) % d == 0) {
        cout << "BestWishes" << endl;
        return;
    }

    a = (y - 1) + (m - 1);
    d = (m - 1) * 2;
    t = m - 1 + x - 1;
    cout << a << ' ' << d << ' ' << ' ' << t << endl;
    if ((t - a) % d == 0) {
        cout << "BestWishes" << endl;
        return;
    }
    cout << "Farewell" << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
    
}