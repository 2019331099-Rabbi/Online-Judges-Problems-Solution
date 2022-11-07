#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

bool check(int64_t arr[], int64_t n, int64_t mid)
{
    int64_t left = 0, help = 0;
    for (int64_t i = 1; i <= n; i++) {
        if (mid > arr[i]) help += (mid - arr[i]) / 2;
        else left += arr[i] - mid;
    }
    return help >= left;
}

void solve()
{
    int64_t n, m, val;

    cin >> n >> m;
    int64_t arr[n + 1] = {0};
    for (int64_t i = 0; i < m; i++) {
        cin >> val;
        arr[val]++;
    }

    int64_t left = 1, right = 2 * m, ans, mid;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (check(arr, n, mid)) ans = mid, right = mid - 1;
        else left = mid + 1;
    }
    cout << ans << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}