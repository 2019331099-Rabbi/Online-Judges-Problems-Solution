#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve(int T)
{
    int n, q;

    cin >> n >> q;
    int64_t arr[n + 1];
    arr[0] = 0;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 2; i <= n; i++) arr[i] += arr[i - 1];

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;

        int64_t sum = arr[n];
        sum -= arr[r] - arr[l - 1];
        sum += k * (r - l + 1);
        if (sum & 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}