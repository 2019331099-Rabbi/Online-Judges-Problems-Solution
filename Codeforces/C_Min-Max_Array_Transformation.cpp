#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve()
{
    int n;

    cin >> n;
    int arr[n], brr[n];

    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) cin >> brr[i];

    int i = 0, j = 0;
    while (i < n) {
        while (j < n && brr[j] < arr[i]) j++;
        cout << brr[j] - arr[i] << ' ';
        i++;
    }
    cout << endl;

    i = n - 1, j = brr[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i + 1] <= brr[i]) brr[i] = j;
        else j = brr[i];
    }
    for (int i = 0; i < n; i++) cout << brr[i] - arr[i] << ' ';
    cout << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}