#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 52
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int answer[sz][sz];
int n, m;

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cout << answer[i][j] << ' ';
        cout << endl;
    }
}

void init()
{
    bool flag = true;
    int i = 0;
    while (i < sz) {
        int j = (flag)?2:0;
        while (j < sz) {
            answer[i][j] = 1;
            j++;
            if (j < sz) {
                answer[i][j] = 1;
                j += 3;
            }
        }
        i++;
        flag = (i % 4 == 0 || (i - 1) % 4 == 0)?true:false;
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}