/**
Problem Link: https://cses.fi/problemset/task/1647
*/

#include <bits/stdc++.h>
#define endl '\n'
#define sz 200010
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int logs[sz];
int sptable[18][sz];

void computeLogs(int n) {
  for (int i = 2; i <= n; i++)
    logs[i] = logs[i / 2] + 1;
}

void buildsptable(int n)
{
    int i, j, len;
    for (i=1; i<=logs[n]; i++) {
        len=1<<i;
        for (j=0; j+len<=n; j++)
            sptable[i][j]=min(sptable[i-1][j], sptable[i-1][j+len/2]);
    }
}

int rmq(int a, int b)
{
    int p=logs[b-a+1];
    return min(sptable[p][a], sptable[p][b-(1<<p)+1]);
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n, q, a, b;
    cin >> n >> q;
    computeLogs(n);
    for (int i=0; i<n; i++) cin >> sptable[0][i];
    buildsptable(n);
    while (q--) {
        cin >> a >> b;
        cout << rmq(a-1, b-1) << endl;
    }
    return 0;
}
