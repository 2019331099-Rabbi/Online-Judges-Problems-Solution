#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100000010
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int fibSum[sz];

void init()
{
    fibSum[0] = 0;
    fibSum[1] = 1;
    for (int64_t i = 2; i < sz; i++) fibSum[i] = (fibSum[i - 1] + fibSum[i - 2]) % mod;
    for (int i = 1; i < sz; i++) fibSum[i] = (fibSum[i] + fibSum[i - 1]) % mod;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();
    int T;
    cin >> T;
    while (T--) {
        int64_t a, b;
        cin >> a >> b;
        if (!a) a++;
        cout << (fibSum[b] - fibSum[a - 1]) % mod << endl;
    }
    return 0;
}