#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 101
#define inf 1e8
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
int col8[]={1, -1, 0, 0, 1, 1, -1, -1};

vector <string> grid;

void bfs()
{
    queue <pair <int, int>> q;
    int i, j, k, r=grid.size(), c=grid[0].size(), cnt, mx=0, xi, yi, x, y;
    for (i=0; i<r; i++) {
        for (j=0; j<c; j++) {
            if (grid[i][j]=='1') {
                cnt=0;
                q.push({i, j});
                grid[i][j]='0';
                while (!q.empty()) {
                    xi=q.front().first;
                    yi=q.front().second;
                    cnt++;
                    q.pop();
                    for (k=0; k<8; k++) {
                        x=xi+row8[k];
                        y=yi+col8[k];
                        if (x<0 || x>=r || y<0 || y>=c) continue;
                        if (grid[x][y]=='0') continue;
                        q.push({x, y});
                        grid[x][y]='0';
                    }
                }
                mx=max(mx, cnt);
            }
        }
    }
    cout << mx << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    bool flag=false;
    int T, i;
    string s;
    cin >> T;
    cin.ignore();
    getline(cin, s);
    while (T--) {
        if (flag) cout << endl;
        flag=true;
        while (getline(cin, s)) {
            if (s.size()) grid.push_back(s);
            else break;
        }
        bfs();
        grid.clear();
    }
    return 0;
}
