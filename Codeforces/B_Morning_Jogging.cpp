#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 2000000000
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
    int n, m;

    cin >> n >> m;
    vector <pair <int, int>> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val;
            cin >> val;
            v.push_back({val, i});
        }
    }
    sort(v.begin(), v.end());
    int ans[n][m], cnt = 0;
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < m; i++) {
        int val = v[i].first;
        int road = v[i].second;
        ans[road][cnt++] = val;
    }
    int col[n] = {0};
    for (int i = m; i < n * m; i++) {
        int val = v[i].first;
        int road = v[i].second;
        int tmp = col[road];
        while (ans[road][tmp]) tmp++;
        ans[road][tmp] = val;
        col[road] = tmp;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << ans[i][j] << ' ';
        cout << endl;
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}