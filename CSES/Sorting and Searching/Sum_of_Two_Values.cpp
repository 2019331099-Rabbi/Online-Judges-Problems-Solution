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
    int n, sum;

    cin >> n >> sum;
    vector <pair <int, int>> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());
    int i = 1, j = n;

    while (i < j) {
        int tmp = v[i].first + v[j].first;
        if (tmp == sum) {
            cout << v[i].second << ' ' << v[j].second << endl;
            return;
        }
        if (tmp < sum) i++;
        else j--;
    }
    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}