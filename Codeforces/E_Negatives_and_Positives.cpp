#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 2000000000
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int64_t row4[]={0, 1, 0, -1};
// int64_t col4[]={1, 0, -1, 0};
 
//int64_t row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int64_t col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int64_t rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int64_t colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

void solve()
{
    int n;

    cin >> n;
    vector <int> v(n);

    int mn = INT_MAX, cnt = 0;
    int64_t sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mn = min(mn, abs(v[i]));
        if (v[i] < 0) cnt++;
        sum += abs(v[i]);
    }
    if (mn == 0) cout << sum << endl;
    else if (cnt & 1) cout << sum - 2 * mn << endl;
    else cout << sum << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}