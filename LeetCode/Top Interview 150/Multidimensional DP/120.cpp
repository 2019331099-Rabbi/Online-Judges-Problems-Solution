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

// Bottom Up Approach: Recursion
class Solution {
private:
    vector <vector <int>> memo;
    int minCost(int r, int c, vector <vector <int>> &triangle) {
        if (r >= triangle.size()) return 0;
        if (memo[r][c] != -1) return memo[r][c];

        int cost1 = minCost(r + 1, c, triangle);
        int cost2 = minCost(r + 1, c + 1, triangle);
        return memo[r][c] = triangle[r][c] + min(cost1, cost2);
    }
public:
    Solution() : memo(201, vector<int>(201, -1)) {} 
    int minimumTotal(vector<vector<int>>& triangle) {
        return minCost(0, 0, triangle);
    }
};

// Bottom Up Approach: Iterative
// class Solution {
// public:
//     int findIndex(int x, int y) {
//         return x * (x + 1) / 2 + y;
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         int len = n * (n + 1) / 2;

//         vector <int> memo(len, INT32_MAX);
//         // Instead of using 2D array, I have used ID array for memoization. I have mapped each index (i, j) to its position in 2D array.
//         for (int i = 0; i < n; i++) memo[findIndex(n - 1, i)] = triangle[n - 1][i];
//         // Bottom up approach, so I initialize the last row with default value.


//         for (int i = n - 2; i >= 0; i--)
//             for (int j = 0; j <= i; j++)
//                 memo[findIndex(i, j)] = triangle[i][j] + min(memo[findIndex(i + 1, j)], memo[findIndex(i + 1, j + 1)]);
//                 /*
//                 From the second last row, for each position, I have found the minimum cost. For example,
//                 traingle:
//                           6
//                         4   1
//                 Here, the memo array initially look like:
//                 memo:
//                           i1
//                         4    1
//                 Now what will be the i1?
//                 We can detemine i1 by 6 + minimum of (4, 1) => 6 + 1 => 7
//                 For each row, i, for each position j, minimum cost will be:
//                     Minimum cost of (i+1)th row + own cost          

//                 NB: For memory saving, I have used memo as ID array. Let in triangle index is (x, y) = (1, 0). What will be the corresponding index in memo?
//                 It is x * (x + 1) / 2 + y = 1 * (1 + 1) / 2 + 0 = 1 + 0 = 1
//                 For this example, memo look like {i1, 4, 1}
//                 */
        
//         return memo[0];
//     }
// };


// Top Down Approach: BFS
// class Solution {
// public:
//     int findIndex(int x, int y) {
//         return x * (x + 1) / 2 + y;
//     }
    
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector <int> memo(n*(n+1)/2, INT32_MAX);
//         queue <pair <int, int>> q;
        
//         q.push({0, 0});
//         memo[0] = triangle[0][0];

//         while (!q.empty()) {
//             int xi = q.front().first;
//             int yi = q.front().second;
//             q.pop();

//             if (xi == n - 1) continue;

//             int idx = findIndex(xi, yi);

//             int newCost = memo[idx] + triangle[xi + 1][yi];
//             int newIdx = findIndex(xi + 1, yi);
//             if (newCost < memo[newIdx]) q.push({xi + 1, yi}), memo[newIdx] = newCost;
//             newCost = memo[idx] + triangle[xi + 1][yi + 1];
//             newIdx = findIndex(xi + 1, yi + 1);
//             if (newCost < memo[newIdx]) q.push({xi + 1, yi + 1}), memo[newIdx] = newCost;
//         }
//         int result = *min_element(memo.begin() + n*(n-1)/2, memo.end());
//         return result;
//     }
// };

int main()
{
    RUN_FAST; cin.tie(nullptr);
    Solution *soln = new Solution();

    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    cout << soln->minimumTotal(triangle) << endl;
    return 0;
}