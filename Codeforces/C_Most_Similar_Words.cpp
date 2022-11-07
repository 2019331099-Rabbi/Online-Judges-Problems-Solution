#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <string> v;

int minDiff(int n, int m)
{
    int mn = inf;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int tmp = 0;
            for (int k = 0; k < m; k++) tmp += abs(v[i][k] - v[j][k]);
            mn = min(mn, tmp);
        }
    }
    return mn;
}

void solve()
{
    int n, m;
    string s;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        v.push_back(s);
    }
    cout << minDiff(n, m) << endl;
    v.clear();
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}