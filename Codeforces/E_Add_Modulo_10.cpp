#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int root[sz];

void init()
{
    int rt = 1, val = 1;
    while (val < 50) {
        root[val] = rt;
        val += (val % 10);
    }
    rt = 3, val = 3;
    while (val < 50) {
        root[val] = rt;
        val += (val % 10);
    }
}

bool check(int ans[], int n)
{
    int val = ans[0];
    for (int i = 1; i < n; i++) if (ans[i] != val) return false;
    return true;
}

void solve()
{
    int n;
    cin >> n;

    int ans[n];
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (val & 1) val += (val % 10);
        if (val % 5 == 0) {}
        else if (val < 40) val = root[val];
        else {
            int tmp = (val - 20) / 20;
            val = root[val - 20 * tmp];
        }
        ans[i] = val;
    }
    cout << (check(ans, n)?"Yes":"No") << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}