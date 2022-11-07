#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int chess[sz][sz];
int n, m;

int findPoints(int x, int y)
{
    int sum = chess[x][y];

    int i = x, j = y;
    while (--i >= 0 && --j >= 0) sum += chess[i][j];
    i = x, j = y;
    while (++i < n && ++j < m) sum += chess[i][j];
    i = x, j = y;
    while (++i < n && --j >= 0) sum += chess[i][j];
    i = x, j = y;
    while (--i >= 0 && ++j < m) sum += chess[i][j];
    return sum;
}

int findMax()
{
    int mx = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) mx = max(mx, findPoints(i, j));
    }
    return mx;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> chess[i][j];
    }
    cout << findMax() << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}