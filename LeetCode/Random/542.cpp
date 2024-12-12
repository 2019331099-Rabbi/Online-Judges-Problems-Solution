#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int row[] = {0, 0, -1, 1};
int col[] = {1, -1, 0, 0};

vector <vector <int>> updateMatrix(vector<vector<int>>& mat)
{
    int n = mat.size(), m = mat[0].size();
    queue <pair <int ,int>> pq;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) mat[i][j] = inf;
            else pq.push({i, j});
        }
    }

    while (!pq.empty()) {
        int xi = pq.front().first;
        int yi = pq.front().second;
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int xf = xi + row[i], yf = yi + col[i];
            if (xf < 0 || xf >= n || yf < 0 || yf >= m) continue;

            int cur = mat[xi][yi] + 1;
            if (mat[xf][yf] > cur) {
                mat[xf][yf] = cur;
                pq.push({xf, yf});
            }
        }
    }
    return mat;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    auto result = updateMatrix(mat);
    for (auto xx: result) {
        for (auto yy: xx) cout << yy << ' ';
        cout << endl;
    }
    return 0;


}