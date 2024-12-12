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
    double myPow(double x, int n) {
        int64_t exp = n;
        if (exp < 0) exp *= -1;
        double mul = 1;
        while (exp) {
            if (exp & 1) mul *= x;
            x *= x, exp >>= 1;
        }
        if (n < 0) mul = 1.0/mul;
        return mul;
    }
};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    Solution *soln = new Solution();

    double x = 2.00000;
    int n = 11;

    cout << soln->myPow(x, n) << endl;
}