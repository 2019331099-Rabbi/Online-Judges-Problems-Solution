/**
Problem Link: https://www.spoj.com/problems/RMQSQ/
*/

#include <bits/stdc++.h>
#define endl '\n'
#define sz 100010
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int logs[sz];
int sptable[17][sz];
void computeLogs(int n) {
  for (int i = 2; i <= n; i++)
    logs[i] = logs[i>>1] + 1;
}

void buildsptable(int n)
{
    int i, j;
    for (i=1; i<=logs[n]; i++) {
        for (j=0; j+(1<<i)<=n; j++)
            sptable[i][j]=min(sptable[i-1][j], sptable[i-1][j+(1<<(i-1))]);
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
    cin >> n;
    computeLogs(n);
    for (int i=0; i<n; i++) cin >> sptable[0][i];
    buildsptable(n);
    cin >> q;
    while (q--) {
        cin >> a >> b;
        cout << rmq(a, b) << endl;
    }
    return 0;
}
