#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 8
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

//int row[]={0, 0, -1, 1};
//int col[]={1, -1, 0, 0};

int row[]={-2, -2, 2, 2, -1, -1, 1, 1};
int col[]={1, -1, 1, -1, 2, -2, 2, -2};

int bfs(int xi, int yi, int xd, int yd)
{
    vector <vector <int>> dis(sz, vector <int>(sz, 0));
    int i, x, y;
    queue <pair <int, int>> q;
    q.push({xi, yi});
    dis[xi][yi]=1;

    while (!q.empty()) {
        xi=q.front().first;
        yi=q.front().second;
        q.pop();
        for (i=0; i<8; i++) {
            x=row[i]+xi;
            y=col[i]+yi;
            if (x<0 || x>=8 || y<0 || y>=8 || dis[x][y]) continue;
            q.push({x, y});
            dis[x][y]=dis[xi][yi]+1;
        }
        if (dis[xd][yd]) return dis[xd][yd]-1;
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    string s1, s2;
    int xi, yi, xd, yd, moves;
    while (cin >> s1 >> s2) {
        xi=s1[1]-'1', yi=s1[0]-'a';
        xd=s2[1]-'1', yd=s2[0]-'a';
        moves=bfs(xi, yi, xd, yd);
        cout << "To get from " << s1 << " to " << s2 << " takes " << moves << " knight moves." << endl;
    }
    return 0;
}
