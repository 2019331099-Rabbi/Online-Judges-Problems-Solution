#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST 
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

// vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
// {
//     vector <pair <int, int>> dis;

//     for (int i = 0; i < points.size(); i++) dis.push_back({points[i][0]*points[i][0] + points[i][1]*points[i][1], i});
//     sort(dis.begin(), dis.end());

//     vector <vector <int>> kpoints;
//     for (int i = 0; i < k; i++) {
//         kpoints.push_back(points[dis[i].second]);
//     }
//     return kpoints;
// }

vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
{
    priority_queue <pair <int, int>> pq;

    for (int i = 0; i < points.size(); i++) {
        pq.push({points[i][0]*points[i][0] + points[i][1]*points[i][1], i});
        if (pq.size() > k) pq.pop();
    }

    vector <vector <int>> kpoints;
    while (!pq.empty()) {
        kpoints.push_back(points[pq.top().second]);
        pq.pop();
    }
    return kpoints;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    vector<vector<int>> points = {
        {3, 3},
        {5, -1},
        {-2, 4}
    };

    int k = 2;

    auto result = kClosest(points, k);

    for (auto xx: result) {
        for (auto yy: xx) cout << yy << ' ';
        cout << endl;
    }

    return 0;
}