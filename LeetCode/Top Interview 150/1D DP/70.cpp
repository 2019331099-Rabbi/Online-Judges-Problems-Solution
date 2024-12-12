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

// class Solution {
// public:
//     int memo[46];
//     Solution() {
//         memset(memo, -1, sizeof(memo));
//     }

//     int climbStairs(int n)
//     {
//         if (n <= 2) return n;
//         if (memo[n] != -1) return memo[n];
//         return memo[n] = climbStairs(n - 1) + climbStairs(n - 2);
//     }
// };

class Solution {
public:
    int climbStairs(int n) {
        int memo[n + 1];
        memo[1] = 1;
        memo[2] = 2;
        
        for (int i = 3; i <= n; i++) memo[i] = memo[i - 1] + memo[i - 2];
        return memo[n];
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    Solution *soln = new Solution();

    int n = 2;
    cout << soln->climbStairs(10) << endl;

    return 0;
}