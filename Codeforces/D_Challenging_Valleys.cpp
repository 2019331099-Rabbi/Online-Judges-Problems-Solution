#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 2000000000
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int64_t row4[]={0, 1, 0, -1};
// int64_t col4[]={1, 0, -1, 0};
 
//int64_t row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int64_t col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int64_t rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int64_t colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

void solve()
{
    int n;

    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector <int> v;
    v.push_back(arr[0]);
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) continue;
        v.push_back(arr[i]);
    }
    int cnt = 0;
    // for (auto xx: v) cout << xx << ' ';
    // cout << endl;
    for (int i = 0; i < v.size(); i++) {
        if (i == 0) {
            if (v.size() > 1 && v[i] < v[i + 1]) cnt++;
        }
        else if (i == v.size() - 1) {
            if (v.size() > 1 && v[i - 1] > v[i]) cnt++;
        }
        else if (v[i] < v[i - 1] && v[i] < v[i + 1]) cnt++;

    }
    if (cnt <= 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}