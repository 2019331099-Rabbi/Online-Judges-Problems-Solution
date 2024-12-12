#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;




int findCircleNum(vector<vector<int>>& isConnected)
{
    int n = isConnected.size();
    bool vis[n] = {0};
    int cnt = 0;

    for (int strt = 0; strt < n; strt++) {
        if (vis[strt]) continue;
        cnt++;
        
        queue <int> q;
        q.push(strt), vis[strt] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < n; i++) {
                if (i == u || vis[i] || !isConnected[u][i]) continue;
                q.push(i);
                vis[i] = true;
            }
        }
    }
    return cnt;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> matrix[i][j];
    }
        
    cout << findCircleNum(matrix) << endl;
    return 0;
}