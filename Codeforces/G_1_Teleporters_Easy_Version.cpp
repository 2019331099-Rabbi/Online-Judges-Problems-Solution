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
    int n, c;
    cin >> n >> c;


    vector <int> ans;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        ans.push_back(i + val);
    }
    sort(ans.begin(), ans.end());

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        c -= ans[i];
        if (c < 0) break;
        cnt++;
    }
    cout << cnt << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}