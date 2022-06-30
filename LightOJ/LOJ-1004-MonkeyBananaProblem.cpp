#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/**
Problem Link: https://lightoj.com/problem/monkey-banana-problem
*/

vector <vector <int>> banana;
int n, memo[sz][sz];

int maxBanana(int row, int col)
{
    if (row == 2 * n - 1) return 0;
    if (memo[row][col] != -1) return memo[row][col];

    int val1 = 0, val2 = 0;
    if (row < n - 1) {
        val1 = banana[row][col] + maxBanana(row + 1, col);
        val2 = banana[row][col] + maxBanana(row + 1, col + 1);
    }
    else {
        if (col == 0) val1 = banana[row][col] + maxBanana(row + 1, col);
        else if (col == banana[row].size() - 1) val1 = banana[row][col] + maxBanana(row + 1, col - 1);
        else {
            val1 = banana[row][col] + maxBanana(row + 1, col - 1);
            val2 = banana[row][col] + maxBanana(row + 1, col);
        }
    }
    return memo[row][col] = max(val1, val2);
}

void init()
{
    memset(memo, -1, sizeof(memo));
}

void solve(int i)
{
    int val;
    vector <int> v;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cin >> val;
            v.push_back(val);
        }
        banana.push_back(v);
        v.clear();
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            cin >> val;
            v.push_back(val);
        }
        banana.push_back(v);
        v.clear();
    }
    init();
    cout << "Case " << i << ": " << maxBanana(0, 0) << endl;
    banana.clear();
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}