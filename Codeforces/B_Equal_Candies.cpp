#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve()
{
    int n;

    cin >> n;
    int arr[n];

    int mn = inf;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mn = min(mn, arr[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i] - mn;
    cout << sum << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}