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
    int p, q;

    cin >> p >> q;
    if (p < q) cout << p << endl;
    else if (p % q) cout << p << endl;
    else cout << "Coming" << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}