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
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int counter = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= points[i - 1][1]) {
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
            else counter++;
        }
        return counter;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution *soln = new Solution();

    vector <vector <int>> points = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8}
    };
    cout << soln->findMinArrowShots(points) << endl;
}