#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 110
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int64_t maxsegment(int arr[], int n)
{
    int64_t mx = arr[0], tmp = 0;
    for (int i = 0; i < n - 1; i++) {
        tmp += arr[i];
        mx = max(mx, tmp);
        if (tmp < 0) tmp = 0;
    }
    tmp = 0;
    for (int i = n - 1; i > 0; i--) {
        tmp += arr[i];
        mx = max(mx, tmp);
        if (tmp < 0) tmp = 0;
    }
    return mx;
}

void solve()
{
    int64_t sum = 0;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    int64_t mx = maxsegment(arr, n);
    if (mx < sum) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}