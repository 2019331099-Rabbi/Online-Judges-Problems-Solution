#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int row4[]={0, 1, 0, -1};
int col4[]={1, 0, -1, 0};
 
//int row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

void solve()
{
    int n;
    cin >> n;
    vector <string> v(n);
    for (auto &xx: v) cin >> xx;
    
    int ans = 0;
    int tmp = n / 2, tmpn = n - 1;
    for (int i = 0; i < tmp; i++) {
        vector <pair <int, int>> pr = {{i, i}, {i, n - i - 1}, {n - i - 1, n - i - 1}, {n - i - 1, i}};
        for (int j = 0; j < tmpn; j++) {
            int cnt1 = 0, cnt0 = 0;
            for (auto xx: pr) {
                if (v[xx.first][xx.second] == '1') cnt1++;
                else cnt0++;
            }
            ans += min(cnt0, cnt1);

            pr[0].first = pr[0].first + row4[0];
            pr[0].second = pr[0].second + col4[0];
            pr[1].first = pr[1].first + row4[1];
            pr[1].second = pr[1].second + col4[1];
            pr[2].first = pr[2].first + row4[2];
            pr[2].second = pr[2].second + col4[2];
            pr[3].first = pr[3].first + row4[3];
            pr[3].second = pr[3].second + col4[3];
        }
        tmpn -= 2;
    }
    cout << ans << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}