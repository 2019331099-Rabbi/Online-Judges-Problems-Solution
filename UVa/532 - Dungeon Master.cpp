#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 31
#define inf 1e8
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int row[]={0, 0, -1, 1};///4 adjacent(Up, down, left, right)
int col[]={1, -1, 0, 0};

int level, r, c, ls, rs, cs, ld, rd, cd, dis[sz][sz][sz];
char ch;

void init()
{
    int i, j, k;
    for (i=0; i<level; i++) {
        for (j=0; j<r; j++) {
            for (k=0; k<c; k++) dis[i][j][k]=0;
        }
    }
}

int bfs()
{
    int li, xi, yi, l, x, y, i;
    queue <int> q1;
    queue <pair <int, int>> q2;
    q1.push(ls), q2.push({rs, cs});
    dis[ls][rs][cs]=1;

    while (!q1.empty()) {
        li=q1.front();
        xi=q2.front().first;
        yi=q2.front().second;
        q1.pop(), q2.pop();
        for (i=0; i<4; i++) {
            x=xi+row[i];
            y=yi+col[i];
            if (y<0 || y>=c) continue;
            if ((li==0 && x<0) || (li==level-1 && x>=r)) continue;

            if (x<0) x=0, l=li-1;
            else if (x>=r) x=r-1, l=li+1;
            else l=li;

            if (dis[l][x][y]) continue;
            dis[l][x][y]=dis[li][xi][yi]+1;
            q1.push(l), q2.push({x, y});
        }
        if (li>0 && !dis[li-1][xi][yi]) {
            q1.push(li-1), q2.push({xi, yi});
            dis[li-1][xi][yi]=dis[li][xi][yi]+1;
        }
        if (li<level-1 && !dis[li+1][xi][yi]) {
            q1.push(li+1), q2.push({xi, yi});
            dis[li+1][xi][yi]=dis[li][xi][yi]+1;
        }
        if (dis[ld][rd][cd]) return dis[ld][rd][cd]-1;
    }
    return 0;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int i, j, k;
    string s;
    while (cin >> level >> r >> c) {
        if (!level && !r && !c) break;
        init();
        for (i=0; i<level; i++) {
            for (j=0; j<r; j++) {
                cin >> s;
                for (k=0; k<c; k++) {
                    ch=s[k];
                    if (ch=='#') dis[i][j][k]=1;
                    else if (ch=='S') ls=i, rs=j, cs=k;
                    else if (ch=='E') ld=i, rd=j, cd=k;
                }
            }
        }
        k=bfs();
        if (k) cout << "Escaped in " << k << " minute(s)." << endl;
        else cout << "Trapped!" << endl;
    }
    return 0;
}
