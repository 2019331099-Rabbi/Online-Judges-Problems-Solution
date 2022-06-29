#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 1001
#define inf 1e9
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int row[]={0, 0, -1, 1};///4 adjacent(Up, down, left, right)
int col[]={1, -1, 0, 0};

//int row[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int col[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

int r, c, fire[sz][sz], dis[sz][sz];
vector <string> v;

void init()
{
    int i, j;
    for (i=0; i<r; i++)
        for (j=0; j<c; j++) fire[i][j]=inf, dis[i][j]=0;
}

void bfs(int xi, int yi)
{
    int i, x, y;
    queue <pair <int, int>> q;
    q.push({xi, yi});
    fire[xi][yi]=1;

    while (!q.empty()) {
        xi=q.front().first;
        yi=q.front().second;
        q.pop();
        for (i=0; i<4; i++) {
            x=xi+row[i];
            y=yi+col[i];
            if (x<0 || x>=r || y<0 || y>=c) continue;
            if (fire[x][y]<=fire[xi][yi]+1 || v[x][y]=='#') continue;
            q.push({x, y});
            fire[x][y]=fire[xi][yi]+1;
        }
    }
}

int bfsout(int xi, int yi)
{
    int i, x, y;
    queue <pair <int, int>> q;
    q.push({xi, yi}), dis[xi][yi]=1;
    while (!q.empty()) {
        xi=q.front().first;
        yi=q.front().second;
        q.pop();
        for (i=0; i<4; i++) {
            x=xi+row[i];
            y=yi+col[i];
            if (x<0 || x>=r || y<0 || y>=c) return dis[xi][yi];
            if (dis[x][y] || v[x][y]=='#' || fire[x][y]<=dis[xi][yi]+1) continue;
            dis[x][y]=dis[xi][yi]+1;
            q.push({x, y});
        }
    }
    return -1;
}

pair <int, int> posj()
{
    int i, j;
    for (i=0; i<r; i++)
        for (j=0; j<c; j++)
        if (v[i][j]=='J') return {i, j};
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T, i, j, k=1;
    string s;
    cin >> T;
    while (T--) {
        cin >> r >> c;
        init();
        for (i=0; i<r; i++) {
            cin >> s;
            v.push_back(s);
        }
        for (i=0; i<r; i++) {
            for (j=0; j<c; j++)
                if (v[i][j]=='F') bfs(i, j);
        }
        pair <int, int> ij=posj();
        i=ij.first, j=ij.second;
        i=bfsout(i, j);
        if (i==-1) cout << "IMPOSSIBLE" << endl;
        else cout << i << endl;
        v.clear();
    }
    return 0;
}
