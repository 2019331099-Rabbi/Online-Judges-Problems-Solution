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

map <string, int> mp;

void solve(int tot, bool flag)
{
    for (auto xx: mp) {
        int cnt = xx.second;
        double ans = cnt * 100.0 / tot;
        cout << fixed << setprecision(4);
        cout << xx.first << ' ' << ans << endl;
    }
    if (flag) cout << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    string s;
    bool flag = false;

    cin >> T;
    cin.ignore();
    int tot = 0;
    while (T) {
        while (getline(cin, s)) {
            if (s.size() == 0) {
                if (flag) solve(tot, true);
                tot = 0;
                mp.clear();
                T--;
                flag = true;
                continue;
            }
            tot++;
            mp[s]++;
        }
    }
    solve(tot, false);
    return 0;
}