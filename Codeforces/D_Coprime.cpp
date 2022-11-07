#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row4[]={0, 1, 0, -1};
// int col4[]={1, 0, -1, 0};
 
//int row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

void solve()
{
    int n;

    cin >> n;
    map <int, int> mp;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        mp[val] = i;
    }
    int ans = INT_MIN;
    for (auto const &xx: mp) {
        int val1 = xx.first, cnt1 = xx.second;
        for (auto const &yy: mp) {
            int val2 = yy.first, cnt2 = yy.second;
            if (__gcd(val1, val2) == 1) ans = max(ans, cnt1 + cnt2);
        }
    }
    if (ans == INT_MIN) cout << -1 << endl;
    else cout << ans << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0; 
}