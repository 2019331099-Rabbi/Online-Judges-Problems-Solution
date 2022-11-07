#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <stack <int>> stk(43);
int values[] = {4, 8, 15, 16, 23, 42};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n, val, i;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> val;
        stk[val].push(i);
    }

    int cnt = 0;
    int tmp = 0;
    while (!stk[42].empty()) {
        val = stk[42].top();
        stk[42].pop();
        for (i = 4; i >= 0; i--) {
            while (!stk[values[i]].empty() && stk[values[i]].top() > val) stk[values[i]].pop();
            if (!stk[values[i]].empty()) {
                val = stk[values[i]].top();
                stk[values[i]].pop();
            }
            else break;
        }
        if (i < 0) cnt++;
        else break;
    }
    cout << n - (cnt * 6) << endl;
    return 0;
}