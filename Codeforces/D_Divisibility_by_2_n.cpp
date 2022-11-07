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
    int64_t cnt = n, arr[n + 1];
    for (int i = 1; i <= n; i++) {
        int64_t val;
        cin >> val;
        while (val % 2 == 0) {
            cnt--;
            val /= 2;
        }
        arr[i] = val * i;
    }
    if (cnt <= 0) cout << 0 << endl;
    else {
        vector <int64_t> v;
        for (int i = 1; i <= n; i++) {
            int64_t val = arr[i], tmp = 0;
            while (val % 2 == 0) tmp++, val /= 2;
            v.push_back(tmp);
        }
        sort(v.rbegin(), v.rend());
        int ans = 0;
        for (auto xx: v) {
            cnt -= xx;
            ans++;
            if (cnt <= 0) break;
        }
        if (cnt > 0) cout << -1 << endl;
        else cout << ans << endl;
    }
    // cout << cnt << endl;
    // for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
    // cout << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}