#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 5000010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

unsigned long long phi[sz + 1];

void phi1ton()
{
    for (int i = 2; i < sz; i++) phi[i] = i;

    for (int i = 2; i < sz; i++) {
        if (phi[i] == i) {
            for (int j = i; j < sz; j += i) phi[j] -= phi[j] / i;
        }
    }
    for (int i = 2; i < sz; i++) phi[i] = phi[i] * phi[i] + phi[i - 1];
}

void solve(int T)
{
    int a, b;
    cin >> a >> b;
    cout << "Case " << T << ": " << phi[b] - phi[a - 1] << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    phi1ton();
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}