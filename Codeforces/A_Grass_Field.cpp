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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    if (a + b + c + d == 0) cout << 0 << endl;
    else if (a + b + c + d == 4) cout << 2 << endl;
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