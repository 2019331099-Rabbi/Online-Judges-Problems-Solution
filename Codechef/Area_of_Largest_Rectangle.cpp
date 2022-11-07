#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 210
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int mat[sz][sz];
int n, m;

int slidingWindow(int i)
{
    stack <int> stk;
    stk.push(0);
    int nextsmaller[m];
    for (int j = 1; j < m; j++) {
        if (mat[i][j] >= mat[i][stk.top()]) {
            stk.push(j);
            continue;
        }
        while (stk.size() && mat[i][j] < mat[i][stk.top()]) {
            nextsmaller[stk.top()] = j;
            stk.pop();
        }
        stk.push(j);
    }
    while (stk.size()) {
        nextsmaller[stk.top()] = m;
        stk.pop();
    }
    int prevsmaller[m];
    stk.push(m - 1);
    for (int j = m - 2; j >= 0; j--) {
        if (mat[i][j] >= mat[i][stk.top()]) {
            stk.push(j);
            continue;
        }
        while (stk.size() && mat[i][j] < mat[i][stk.top()]) {
            prevsmaller[stk.top()] = j;
            stk.pop();
        }
        stk.push(j);
    }
    while (stk.size()) {
        prevsmaller[stk.top()] = -1;
        stk.pop();
    }
    int mxarea = -inf;
    for (int j = 0; j < m; j++) mxarea = max(mxarea, (nextsmaller[j] - prevsmaller[j] - 1) * mat[i][j]);
    return mxarea;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> mat[i][j];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (mat[j][i]) mat[j][i] += mat[j - 1][i];
        }
    }

    int ans = INT_MIN;
    for (int i = 0; i < n; i++) ans = max(ans, slidingWindow(i));
    cout << ans << endl;
    return 0;
}