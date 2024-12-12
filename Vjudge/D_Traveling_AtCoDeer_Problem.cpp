#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 100000
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve(int T)
{
    
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n, mx = -1, mn = inf;

    cin >> n;
    while (n--) {
        int val;
        cin >> val;
        mn = min(mn, val);
        mx = max(mx, val);
    }
    cout << mx - mn << endl;

    return 0;
}