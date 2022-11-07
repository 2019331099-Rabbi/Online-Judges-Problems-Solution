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
    vector <int> v1(n), v2(n);

    for (auto &xx: v1) cin >> xx;
    for (auto &xx: v2) cin >> xx;
    

    for (int i = 0; i < n; i++) if (v1[i] > v2[i]) swap(v1[i], v2[i]);

    int64_t sum = 0;
    for (int i = 1; i < n; i++) sum += abs(v1[i] - v1[i - 1]);
    for (int i = 1; i < n; i++) sum += abs(v2[i] - v2[i - 1]);

    cout << sum << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}