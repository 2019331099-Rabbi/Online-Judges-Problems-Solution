#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 1000
#define inf 1e8
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int row8[]={-1, -1, 0, 1, 1, 1, 0, -1};///8 adjacent
int col8[]={0, 1, 1, 1, 0, -1, -1, -1};

int r, c, vis[sz][sz], n, xi, yi, xd, yd, x, y, tmpc, tmp, w;
vector <string> v;

void init()
{
    int i, j;
    for (i=0; i<r; i++) fill(vis[i], vis[i]+c, -1);
}

void bfs()
{
    int i;
    cin >> n;
    while (n--) {
        cin >> xi >> yi >> xd >> yd;
        xi--, yi--, xd--, yd--;
        init();
        deque <pair <int, int>> q;
        q.push_back({xi, yi});
        vis[xi][yi]=0;

        while (!q.empty()) {
            xi=q.front().first;
            yi=q.front().second;
            q.pop_front();
            if (xi==xd && yi==yd) {
                cout << vis[xi][yi] << endl;
                break;
            }
            tmp=v[xi][yi]-'0';
            x=xi+row8[tmp];
            y=yi+col8[tmp];

            if (x>=0 && x<r && y>=0 && y<c && (vis[x][y]==-1 || vis[x][y]>vis[xi][yi])) {
                q.push_front({x, y});
                vis[x][y]=vis[xi][yi];
            }
            for (i=0; i<8; i++) {
                x=xi+row8[i];
                y=yi+col8[i];
                if (x>=0 && x<r && y>=0 && y<c && (vis[x][y]==-1 || vis[x][y]>vis[xi][yi])) {
                    q.push_back({x, y});
                    vis[x][y]=vis[xi][yi]+1;
                }
            }
        }
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int i;
    string s;
    cin >> r >> c;
    for (i=0; i<r; i++) {
        cin >> s;
        v.push_back(s);
    }
    bfs();
    v.clear();
    return 0;
}
