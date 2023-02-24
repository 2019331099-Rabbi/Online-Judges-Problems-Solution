#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int logs[sz];
int sptable[18][sz];

void computeLogs(int n)
{
    logs[1] = 0;
    for (int i = 2; i <= n; i++) logs[i] = logs[i / 2] + 1;
}

void buildTable(int n)
{
    for (int i = 1; i <= logs[n]; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            sptable[i][j] = min(sptable[i - 1][j], sptable[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int rmq(int l, int r)
{
    int p = logs[r - l + 1];
    return min(sptable[p][l], sptable[p][r - (1 << p) + 1]);
}

void solve(int T)
{
    int n, q;

    cin >> n >> q;
    computeLogs(n);
    for (int i = 0; i < n; i++) cin >> sptable[0][i];
    buildTable(n);

    int l, r;
    cout << "Case " << T << ":" << endl;
    while (q--) {
        cin >> l >> r;
        cout << rmq(l - 1, r - 1) << endl;
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}