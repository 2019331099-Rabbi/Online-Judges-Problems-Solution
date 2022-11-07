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
    int n, cnt = 0;
    
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 1) cnt++;
        vis[arr[i]]++;
    }
    if (cnt == 1) cout << 1 << endl;
    else if (cnt > 1) cout << 0 << endl;
    else {

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int val = arr[i];
            bool flag = true;
            for (int i = 2; i * i <= val; i++) {
                if (val % i == 0) {
                    int d1 = i;
                    int d2 = val / i;
                    if (vis[d1] || vis[d2]) {
                        flag = false;
                        break;
                    }
                }
            }
            if (vis[val] > 1) flag = false;
            if (flag) ans++;
        }

        cout << ans << endl;
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    solve();
}