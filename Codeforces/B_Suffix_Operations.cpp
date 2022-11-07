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
    int64_t arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int64_t sum = 0;
    for (int i = 1; i < n; i++) sum += abs(arr[i] - arr[i - 1]);
    int64_t ans  = min(sum - abs(arr[0] - arr[1]), sum - abs(arr[n - 1] - arr[n - 2]));

    for (int i = 1; i < n - 1; i++)
        ans=min(ans, sum-(abs(arr[i] - arr[i - 1]) + abs(arr[i + 1] - arr[i]) - abs(arr[i - 1] - arr[i + 1])));
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