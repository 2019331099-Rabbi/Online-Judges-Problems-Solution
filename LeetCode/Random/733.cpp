#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
{
    int prevColor = image[sr][sc];
    if (prevColor == color) return image;

    int n = image.size(), m = image[0].size();
    queue <pair <int, int>> pq;

    pq.push({sr, sc});
    image[sr][sc] = color;
    while (!pq.empty()) {
        sr = pq.front().first;
        sc = pq.front().second;
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int rf = sr + row[i];
            int cf = sc + col[i];
            if (rf < 0 || rf >= n || cf < 0 || cf >= m || image[rf][cf] != prevColor) continue;
            image[rf][cf] = color;
            pq.push({rf, cf});
        }
    }
    return image;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);

    vector <vector <int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, color = 2;
    auto result = floodFill(image, sr, sc, color);

    for (auto xx: result) {
        for (auto yy: xx) cout << yy << ' ';
        cout << endl;
    }

    return 0;
}