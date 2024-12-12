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
    int uniquePaths(int m, int n) {
        vector <vector <int>> memo(m + 1, vector <int>(n + 1, -1));

        function<int(int, int)> pathFinding = [&](int xi, int yi) -> int {
            if (xi == m && yi == n) return 1;
            if (xi > m || yi > n) return 0;
            if (memo[xi][yi] != -1) return memo[xi][yi];

            return memo[xi][yi] = pathFinding(xi, yi + 1) + pathFinding(xi + 1, yi);
        };

        return pathFinding(1, 1);
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    cout << soln->uniquePaths(3, 7) << endl;
}