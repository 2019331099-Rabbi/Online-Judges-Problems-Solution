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
    int arr[n + 1];
    int saved[sz];

    saved[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        saved[arr[i]] = arr[i];
    }

    int cnt = 0, l = 0;
    for (int i = 2; i <= n; i++) {
        arr[i] = saved[arr[i]], arr[i - 1] = saved[arr[i - 1]];
        if (arr[i] >= arr[i - 1]) continue;

        cnt++;
        saved[arr[i - 1]] = 0;
        for (int j = i - 2; j > l; j--) {
            if (saved[arr[j]] != 0) {
                cnt++;
                saved[arr[j]] = 0;
            }
        }
        l = i - 1;
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