#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 1000
#define inf 1e9
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int row[]={0, 0, -1, 1};///4 adjacent(Up, down, left, right)
int col[]={1, -1, 0, 0};

//int row[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int col[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

int adj[sz][sz], r, c, cost[sz][sz];

void init()
{
    int i, j;
    for (i=0; i<r; i++)
        for (j=0; j<c; j++) cost[i][j]=inf;
}

void dijkstra()
{
    int xi, yi, x, y, i, dis;
    priority_queue <pair <int, pair <int, int>>, vector <pair <int, pair <int, int>>>, greater <pair <int, pair <int, int>>>> pq;
    pq.push({0, {0, 0}});
    cost[0][0]=adj[0][0];
    while (!pq.empty()) {
        xi=pq.top().second.first;
        yi=pq.top().second.second;
        pq.pop();
        for (i=0; i<4; i++) {
            x=xi+row[i];
            y=yi+col[i];
            if (x<0 || x>=r || y<0 || y>=c) continue;
            dis=cost[xi][yi]+adj[x][y];
            if (cost[x][y]<=dis) continue;
            cost[x][y]=dis;
            pq.push({dis, {x, y}});
        }
    }
    cout << cost[r-1][c-1] << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T, i, j;
    cin >> T;
    while (T--) {
        cin >> r >> c;
        init();
        for (i=0; i<r; i++) {
            for (j=0; j<c; j++) cin >> adj[i][j];
        }
        dijkstra();
    }
    return 0;
}
