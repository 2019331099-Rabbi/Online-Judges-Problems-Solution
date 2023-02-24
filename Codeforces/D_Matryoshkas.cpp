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

map <int, int> mp;

void solve()
{
    int n;

    cin >> n;
    while (n--) {
        int val;
        cin >> val;
        mp[val]++;
    }
    int lstval = -1, lst = 0, cnt = 0;
    for (auto it: mp) {
        if (it.first == lstval + 1) cnt += max(0, it.second - lst);
        else cnt += it.second;

        lstval = it.first, lst = it.second;
    }
    cout << cnt << endl;
    mp.clear();
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}