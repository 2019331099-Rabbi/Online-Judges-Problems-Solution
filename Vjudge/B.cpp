#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1000001
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int vis[sz];

void solve()
{
    int n;

    cin >> n;
    int arr[n], ans[n];
    for (int i = 0; i < n; i++) ans[i] = inf;

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            int cnt = 1, j = i - 1;
            if (j < n - 1) ans[j + 1] = 0;
            while (j >=0 && arr[j]) {
                ans[j] = min(ans[j], cnt);
                cnt++;
                j--;
            }
            cnt = 1;
            j = i + 1;
            while (j < n && arr[j]) {
                ans[j] = min(ans[j], cnt);
                cnt++;
                j++;
            }
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    solve();
}