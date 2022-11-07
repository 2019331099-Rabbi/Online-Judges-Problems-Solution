#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int64_t row4[]={0, 1, 0, -1};
// int64_t col4[]={1, 0, -1, 0};
 
//int64_t row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int64_t col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int64_t rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int64_t colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

vector <string> v;

void solve()
{
    int64_t n, q;
    
    cin >> n >> q;
    vector <int64_t> arr(n), presum(n);
    for (int64_t i = 0; i < n; i++) {
        cin >> arr[i];
        presum[i] = arr[i];

    }
    for (int64_t i = 1; i < n; i++) presum[i] += presum[i - 1];
    for (int64_t i = 1; i < n; i++) arr[i] = max(arr[i - 1], arr[i]);

    // for (int64_t i = 0; i < n; i++) cout << arr[i] << ' ';
    // cout << endl;
    // for (int64_t i = 0; i < n; i++) cout << presum[i] << ' ';
    // cout << endl;

    while (q--) {
        int64_t val;
        cin >> val;
        int64_t tmp = upper_bound(arr.begin(), arr.end(), val) - arr.begin();
        tmp--;
        if (tmp < 0) cout << 0 << ' ';
        else cout << presum[tmp] << ' ';
    }
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