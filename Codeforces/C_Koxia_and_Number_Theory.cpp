#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 2000000000
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row4[]={0, 1, 0, -1};
// int col4[]={1, 0, -1, 0};
 
//int row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

void solve()
{
    int n;
    vector <int64_t> arr;
    map <int64_t, int64_t> mp;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int64_t val;
        cin >> val;
        arr.push_back(val + 1);
        mp[val + 1]++;
    }

    bool flag = true;
    for (auto it: mp) if (it.second > 1) flag = false;

    int64_t cnto = 0;
    for (auto xx: arr) if (xx & 1) cnto++;
    int64_t cnte = n - cnto;

    if (!flag) cout << "NO" << endl;
    else if (cnte > 1 && cnto > 1) cout << "NO" << endl;
    else cout << "YES" << endl; 
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

/*
25 5 1 106.8
64 8 1 177.2
144 12 1 279.2
*/