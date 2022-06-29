#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 2500
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

//int row[]={0, 0, -1, 1};///4 adjacent(Up, down, left, right)
//int col[]={1, -1, 0, 0};

//int row[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int col[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

vector <int> adj[sz];
int nodes;

void bfs(int source)
{
    int i, x, tmp, level[nodes+1]={0}, ans[nodes+1]={0}, ltmp;
    queue <int> q;
    q.push(source);
    level[source]=1;

    while (!q.empty()) {
        x=q.front();
        ltmp=level[x];
        q.pop();
        for (i=0; i<adj[x].size(); i++) {
            tmp=adj[x][i];
            if (level[tmp]) continue;
            q.push(tmp);
            level[tmp]=ltmp+1;
            ans[ltmp]++;
        }
    }
    if (ltmp==1) {
        cout << 0 << endl;
        return;
    }
    x=ans[1], tmp=1;
    for (i=2; i<=ltmp; i++) {
        if (ans[i]>x) {
            x=ans[i];
            tmp=i;
        }
    }
    cout << x << ' ' << tmp << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int i, n, edges, T;
    cin >> nodes;
    for (i=0; i<nodes; i++) {
        cin >> n;
        while (n--) {
            cin >> edges;
            adj[i].push_back(edges);
        }
    }
    cin >> T;
    while (T--) {
        cin >> edges;
        bfs(edges);
    }
    return 0;
}
