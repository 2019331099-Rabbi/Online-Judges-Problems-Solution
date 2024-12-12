#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1001
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST 
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        int globalMax = 1;
        for (int i = 0; i < len; i++) {
            unordered_map <string, int> ump;
            for (int j = i + 1; j < len; j++) {
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];

                string slope;
                if (dx == 0) slope = "inf";
                else if (dy == 0) slope = "0";
                else {
                    int gcd = __gcd(dx, dy);
                    dx /= gcd;
                    dy /= gcd;
                    if (dx < 0) dx = -dx, dy = -dy;
                    slope = to_string(dy) + "/" + to_string(dx);
                }
                ump[slope]++;
            }
            int localMax = 1;
            for (auto &slope: ump) localMax = max(localMax, slope.second + 1);
            globalMax = max(globalMax, localMax);
        }
        return globalMax;
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    Solution *soln = new Solution();

    vector<vector<int>> points = {{3, 2}, {4, 1}, {2, 3}, {1, 4}, {1, 1}, {5, 3}};
    // vector<vector<int>> points = {{3, 2}, {4, 1}};

    cout << soln->maxPoints(points) << endl;

    return 0;
}