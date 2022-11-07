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
    int n, k;

    cin >> n >> k;
    if (n == k) {
        cout << -1 << endl;
        return;
    }
    else {
        int arr[n + 1];
        int i = n;
        while (k--) {
            arr[i] = i;
            i--;
        }
        for (int j = 1; j <= i; j++) arr[j] = j + 1;
        arr[i] = 1;
        for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
        cout << endl;
    }
    
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    solve();
}