#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 2300
#define inf 5000010
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

unsigned long long ans[inf];

void phi()
{
    for (int i = 2; i < inf; i++) ans[i] = i;
    for (int i = 2; i < inf; i++) {
        if (ans[i] == i) {
            for (int j = i; j < inf; j += i) ans[j] -= ans[j] / i;
        }
    }
    for (int i = 2; i < inf; i++) ans[i] = (ans[i] * ans[i]) + ans[i - 1];
}

void solve(unsigned long long T)
{
    unsigned long long a, b;
    cin >> a >> b;
    cout << "Case " << T << ": " << ans[b] - ans[a - 1] << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    phi();
    unsigned long long T;
    cin >> T;
    for (unsigned long long i = 1; i <= T; i++) solve(i);
    return 0;
}