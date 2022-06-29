#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 101
#define inf 1e8
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int rowk[]={0, 0, -1, 1, 1, -1, -1, 1};///4 adjacent(Up, down, left, right)
int colk[]={1, -1, 0, 0, 1, 1, -1, -1};

int rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
int colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

int r, c, x, y, vis[sz][sz];
vector <string> forest;
vector <pair <int, int>> posab(2);

void init()
{
    int i, j;
    for (i=0; i<r; i++)
        for (j=0; j<c; j++) vis[i][j]=0;
    forest.clear();
}

void bfs(int xi, int yi)
{
    int i;
    vis[xi][yi]=1;
    for (i=0; i<8; i++) {
        x=xi+rowkt[i];
        y=yi+colkt[i];
        if (x<0 || x>=r || y<0 || y>=c) continue;
        if (vis[x][y]) continue;
        vis[x][y]=1;
    }
}

int bfsr()
{
    queue <pair <int, int>> q;
    int d1, d2, xi, yi, i;
    xi=posab[0].first, yi=posab[0].second;
    d1=posab[1].first, d2=posab[1].second;
    vis[d1][d2]=0;
    q.push({xi, yi}), vis[xi][yi]=1;
    while (!q.empty()) {
        xi=q.front().first;
        yi=q.front().second;
        q.pop();
        for (i=0; i<8; i++) {
            x=xi+rowk[i];
            y=yi+colk[i];
            if (x<0 || x>=r || y<0 || y>=c) continue;
            if (vis[x][y]) continue;
            vis[x][y]=vis[xi][yi]+1;
            q.push({x, y});
        }
        if (vis[d1][d2]) return vis[d1][d2]-1;
    }
    return 0;
}

int main()
{
    RUN_FAST; //cin.tie(nullptr);
    int T, i, j;
    char ch;
    string s, ans1="King Peter, you can't go now!", ans2="Minimal possible length of a trip is ";
    cin >> T;
    while (T--) {
        cin >> r >> c;
        init();
        for (i=0; i<r; i++) {
            cin >> s;
            forest.push_back(s);
        }
        for (i=0; i<r; i++) {
            for (j=0; j<c; j++) {
                ch=forest[i][j];
                if (ch=='A' || ch=='B') posab[ch-'A']={i, j};
                else if (ch=='Z') bfs(i, j);
            }
        }
        i=bfsr();
        if (i) cout << ans2 << i << endl;
        else cout << ans1 << endl;
    }
    return 0;
}
