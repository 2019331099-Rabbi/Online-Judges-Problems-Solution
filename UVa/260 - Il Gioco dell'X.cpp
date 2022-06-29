#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 201
#define inf 1e8
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int row[]={-1, -1, 0, 0, 1, 1};
int col[]={-1, 0, -1, 1, 0, 1};

vector <string> grid(sz);
int n;

bool bfs()
{
    queue <pair <int, int>> q;
    int i, j, xi, yi, x, y;
    char ch1='w', ch2='b';
    for (i=0; i<n; i++) {
        if (grid[i][0]==ch1) {
            q.push({i, 0});
            grid[i][0]=ch2;
            while (!q.empty()) {
                xi=q.front().first;
                yi=q.front().second;
                q.pop();
                for (j=0; j<6; j++) {
                    x=xi+row[j];
                    y=yi+col[j];
                    if (x<0 || x>=n || y<0 || y>=n) continue;
                    if (grid[x][y]==ch1) {
                        if (y==n-1) return true;
                        q.push({x, y});
                        grid[x][y]=ch2;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int i, T=1;
    while (cin >> n && n) {
        for (i=0; i<n; i++) cin >> grid[i];
        if (bfs()) cout << T++ << " W" << endl;
        else cout << T++ << " B" << endl;
    }
    return 0;
}
