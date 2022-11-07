#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

bool check(int n, int arr[], int pos)
{
    for (int i = pos + 1; i < n; i++) if (arr[i] > arr[i - 1]) return false;
    for (int i = 1; i < pos; i++) if (arr[i] < arr[i - 1]) return false;
    return true;
}

void solve()
{
    int n;

    cin >> n;
    int arr[n];

    int mx = -inf, mxpos = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > mx) mx = arr[i], mxpos = i;
    }
    cout << ((check(n, arr, mxpos))?"YES":"NO") << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}