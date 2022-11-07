#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve()
{
    int n, k, cnt = 0;

    cin >> n >> k;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        arr[val] = i;
    }

    for (int i = 1; i <= k; i++) {
        if (arr[i] > k) cnt++;
    }
    cout << cnt << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}