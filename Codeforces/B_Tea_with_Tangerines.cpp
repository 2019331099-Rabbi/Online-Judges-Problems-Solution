#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 33000
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

    vector <int> v(n);
    int mn = INT_MAX, mx;
    for (auto &xx: v) {
        cin >> xx;
        mn = min(mn, xx);
    }
    mx = mn * 2 - 1;
    
    int ans = 0;
    for (auto xx: v) {
        int tmp = ceil((double)(xx - mx) / mx);
        ans += min(tmp, (xx - mn) / mn);
    }
    cout << ans << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}