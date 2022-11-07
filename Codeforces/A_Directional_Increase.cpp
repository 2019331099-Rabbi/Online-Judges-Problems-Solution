                    #include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

bool isPossible(int n, int64_t arr[])
{
    int tmp = 0;
    for (int i = 0; i < n; i++) if (arr[i]) tmp = i;
    n = tmp + 1;
    for (int i = 1; i < n; i++) arr[i] += arr[i - 1];

    if (arr[n - 1]) return false;

    for (int i = 0; i < n; i++) {
        if (arr[i] <= 0 && i < n - 1) return false;
    }
    return true;
}

void solve()
{
    int n;

    cin >> n;
    int64_t arr[n];

    for (int i = 0; i < n; i++) cin >> arr[i];
    if (isPossible(n, arr)) cout << "Yes" << endl;
    else cout << "No" << endl;

}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}