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
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
 
    map <int, int> mp;
    int ans = INT_MIN, prev = 0;
    for (int i = 1; i <= n; i++) {
        int pos = mp[v[i]];
        if (!pos || pos < prev) ans = max(ans, i - prev);
        else prev = pos;
        mp[v[i]] = i;
    }
    cout << ans << endl;
}
 
int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}