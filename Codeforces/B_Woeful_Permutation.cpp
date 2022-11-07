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
    int n, i;
    
    cin >> n;
    int arr[n + 1];

    for (i = 1; i <= n; i++) arr[i] = i;
    i = 1;
    if (n & 1) i++;
    while (i < n) swap(arr[i], arr[i + 1]), i += 2;

    for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
    cout << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}