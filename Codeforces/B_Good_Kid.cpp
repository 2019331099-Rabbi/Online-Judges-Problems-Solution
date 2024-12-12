#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve(int T)
{
    int n;
    cin >> n;
    vector <int> v(n);

    for (auto &xx: v) cin >> xx;

    sort(v.begin(), v.end());
    v[0]++;

    for (int i = 1; i < n; i++) v[0] *= v[i];

    cout << v[0] << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}