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
    vector <int> v(n), ans;
    for (auto &xx: v) cin >> xx;

    int prev = 0;
    // cout << prev << endl;

    for (int i = 0; i < n; i++) {
        int cur, idx = -1, mx = -1;
        for (int j = i; j < n; j++) {
            cur = prev | v[j];
            if (cur > mx) idx = j, mx = cur;
        }
        if (mx > prev) {
            swap(v[i], v[idx]);
            prev = mx;
        }
        else break;
        // cout << prev << endl;
        // for (auto xx: v) cout << xx << ' ';
        // cout << endl;
    }
    for (auto xx: v) cout << xx << ' ';
    cout << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}