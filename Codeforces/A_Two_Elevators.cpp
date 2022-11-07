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
    int a, b, c;

    cin >> a >> b >> c;
    int ans1 = a;
    int ans2 = abs(b - c) + c;

    if (ans1 == ans2) cout << 3 << endl;
    else if (ans1 > ans2) cout << 2 << endl;
    else cout << 1 << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}