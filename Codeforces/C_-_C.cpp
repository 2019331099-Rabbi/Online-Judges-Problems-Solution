#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 2000000000
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int64_t64_t row4[]={0, 1, 0, -1};
// int64_t64_t col4[]={1, 0, -1, 0};
 
//int64_t64_t row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int64_t64_t col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int64_t64_t rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int64_t64_t colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

void solve()
{
    int64_t n, h;

    cin >> n >> h;
    vector <int64_t> v(n);

    for (auto &xx: v) cin >> xx;
    sort(v.rbegin(), v.rend());

    // for (auto xx: v) cout << xx << ' ';
    // cout << endl;

    int64_t cnt = 0;
    int64_t row = v[0];

    for (int64_t i = 0; i < n - 1; i++) {
        if (row == 1) {
            // cout << v[i] << ' ' << cnt << endl;
            cnt += v[i] - 1;
            
            continue;
        }
        int64_t diff = v[i] - v[i + 1];
        
        if (diff <= 1) {
            cnt += v[i] - 1;
            row--;
        }
        else {
            cnt += v[i] - row;
            // if (v[i] == 13) cout << cnt << endl;
            v[i] = row;
            if (v[i] <= v[i + 1]) cnt += row - 1;
            else cnt += v[i + 1];
            row = min(row - 1, v[i + 1]);
        }
        // cout << v[i] << ' ' << cnt << ' ' << row << endl;
    }
    // cout << cnt << endl;

    if (n > 1) {
        if (v[n - 1] - row > 0) {
            cnt += v[n - 1] - row;
        }
        else {
            if (row == 1) cnt += v[n - 1] - 1;
            else if (v[n - 1] == v[n - 2]) cnt++;
        }
    }
    cout << cnt << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    // int64_t T;
    // cin >> T;
    // while (T--)
    solve();
    return 0;
}