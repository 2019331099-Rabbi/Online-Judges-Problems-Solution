#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 300
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t n;

    while (cin >> n and n) {
        int64_t arr[n];
        for (int64_t i = 0; i < n; i++) cin >> arr[i];
        stack <int64_t> stk;

        stk.push(0);
        int64_t nextsmaller[n];
        for (int64_t i = 1; i < n; i++) {
            if (arr[i] >= arr[stk.top()]) {
                stk.push(i);
                continue;
            }
            while (stk.size() && arr[i] < arr[stk.top()]) {
                nextsmaller[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while (stk.size()) {
            nextsmaller[stk.top()] = n;
            stk.pop();
        }
        int64_t prevsmaller[n];
        stk.push(n - 1);
        for (int64_t i = n - 2; i >= 0; i--) {
            if (arr[i] >= arr[stk.top()]) {
                stk.push(i);
                continue;
            }
            while (stk.size() && arr[i] < arr[stk.top()]) {
                prevsmaller[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        while (stk.size()) {
            prevsmaller[stk.top()] = -1;
            stk.pop();
        }
        int64_t mxarea = -inf;
        for (int64_t i = 0; i < n; i++) mxarea = max(mxarea, (nextsmaller[i] - prevsmaller[i] - 1) * arr[i]);
        cout << mxarea << endl;
    }
    return 0;
}