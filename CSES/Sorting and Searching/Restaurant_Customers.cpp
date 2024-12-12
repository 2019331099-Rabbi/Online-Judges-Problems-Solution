#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

set <int> st;
map <int, int> mp;


void solve()
{
    int n;

    cin >> n;
    vector <pair <int, int>> pr(n);
    for (auto &xx: pr) cin >> xx.first >> xx.second;

    sort(pr.begin(), pr.end());
    // for (auto xx: pr) cout << xx.first << ' ' << xx.second << endl;
    // cout << endl;

    priority_queue <int, vector <int>, greater <int>> pq;
    int mx = -inf;
    for (auto xx: pr) {
        pq.push(xx.second);
        while (pq.top() < xx.first) pq.pop();
        int tmp = pq.size();
        mx = max(mx, tmp);

        // cout << xx.second << ' ' << mx << endl;
    }
    cout << mx << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}