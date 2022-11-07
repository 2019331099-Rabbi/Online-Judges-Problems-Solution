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
    int m;
    string s1, s2;

    cin >> m >> s1 >> s2;

    for (int i = 0; i < m; i++) if (s1[i] == 'G') s1[i] = 'B';
    for (int i = 0; i < m; i++) if (s2[i] == 'G') s2[i] = 'B';

    if (s1 == s2) cout << "YES" << endl;
    else cout << "NO" << endl;

}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}