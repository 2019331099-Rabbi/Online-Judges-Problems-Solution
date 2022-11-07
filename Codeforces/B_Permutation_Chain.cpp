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
    int n;

    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) arr[i] = i;

    cout << n << endl;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) cout << arr[j] << ' ';
        cout << endl;
        swap(arr[i], arr[i - 1]);
    }
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}