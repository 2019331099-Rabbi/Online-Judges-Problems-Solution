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

void minTemp(int pos[], int temp[], int n, int k)
{
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
    int ans[n + 1];
    for (int i = 1; i <= n; i++) ans[i] = inf;

    for (int i = 1; i <= k; i++) pq.push({temp[i], pos[i]}), ans[pos[i]] = temp[i];
    while (!pq.empty()) {
        int tmp = pq.top().first;
        int x = pq.top().second;
        pq.pop();

        if (x < n && tmp + 1 < ans[x + 1]) pq.push({tmp + 1, x + 1}), ans[x + 1] = tmp + 1;
        if (x > 0 && tmp + 1 < ans[x - 1]) pq.push({tmp + 1, x - 1}), ans[x - 1] = tmp + 1;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << endl;
}

void solve()
{
    int n, k;

    cin >> n >> k;
    int pos[k + 1], temp[k + 1];
    for (int i = 1; i <= k; i++) cin >> pos[i];
    for (int i = 1; i <= k; i++) cin >> temp[i];
    minTemp(pos, temp, n, k);
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}