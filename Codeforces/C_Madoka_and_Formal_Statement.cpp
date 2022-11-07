#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row4[]={0, 1, 0, -1};
// int col4[]={1, 0, -1, 0};
 
//int row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

bool check(vector <int> arr, vector <int> brr)
{
    if (arr == brr) return true;

    int n = arr.size();
    arr.push_back(arr[0]);
    brr.push_back(brr[0]);
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > brr[i]) return false;
        if (arr[i] == brr[i]) continue;

        if (abs(brr[i] - brr[i + 1]) <= 1) continue;
        if (brr[i + 1] > brr[i]) continue;
        return false;
    }
    return true;
}

void solve()
{
    int n;

    cin >> n;
    vector <int> arr(n), brr(n);
    for (auto &xx: arr) cin >> xx;
    for (auto &xx: brr) cin >> xx;

    if (check(arr, brr)) cout << "YES" << endl;
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