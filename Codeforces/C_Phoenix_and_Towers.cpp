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
    int n, m, k;

    cin >> n >> m >> k;
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
    cout << "YES" << endl;
    for (int i = 1; i <= m; i++) {
        cout << i << ' ';
        pq.push({v[i], i});
    }
    for (int i = m + 1; i <= n; i++) {
        int h = pq.top().first;
        int cnt = pq.top().second;
        cout << cnt << ' ';
        pq.pop();
        pq.push({h + v[i], cnt});
    }
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