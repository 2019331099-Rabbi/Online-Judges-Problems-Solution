#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 21
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

//int row[]={0, 0, -1, 1};
//int col[]={1, -1, 0, 0};

int bfs(int strt, int dest, vector <int> adj[])
{
    int dis[21]={0}, x, len, i, tmp;
    queue <int> q;
    q.push(strt);
    dis[strt]=1;

    while (!q.empty()) {
        x=q.front();
        q.pop();
        len=adj[x].size();
        for (i=0; i<len; i++) {
            tmp=adj[x][i];
            if (dis[tmp]) continue;
            q.push(tmp);
            dis[tmp]=dis[x]+1;
        }
        if (dis[dest]) return dis[dest];
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int i, j, cnt, node, T, strt, dest, test=1;
    while (cin >> cnt) {
        vector <int> adj[sz];
        for (i=0; i<cnt; i++) {
            cin >> node;
            adj[1].push_back(node);
            adj[node].push_back(1);
        }
        for (i=2; i<=19; i++) {
            cin >> cnt;
            for (j=0; j<cnt; j++) {
                cin >> node;
                adj[i].push_back(node);
                adj[node].push_back(i);
            }
        }
        cout << "Test Set #" << test++ << endl;
        cin >> T;
        while (T--) {
            cin >> strt >> dest;
            cnt=bfs(strt, dest, adj);
            if (strt<10) cout << ' ';
            cout << strt << " to ";
            if (dest<10) cout << ' ';
            cout << dest << ": " << cnt-1 << endl;
        }
        cout << endl;
    }
    return 0;
}
