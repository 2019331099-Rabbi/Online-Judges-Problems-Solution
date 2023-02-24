#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 50000
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

bool siv[sz + 1];
vector <int64_t> primes;

void gen_p()
{
    for (int i = 3; i * i <= sz; i += 2) {
        if (!siv[i]) {
            for (int j = i * i; j <= sz; j += i + i) siv[j] = true;
        }
    }
    primes.push_back(2ll);
    for (int64_t i = 3; i <= sz; i += 2) if (!siv[i]) primes.push_back(i);
}

int segSiv(int64_t l, int64_t r)
{
    int len = r - l + 1;
    int seg[len + 1] = {false};

    for (int i = 0; primes[i] * primes[i] <= r; i++) {
        int64_t p = primes[i];
        int64_t strt = (l / p) * p;
        if (strt < l) strt += p;
        for (int64_t j = strt; j <= r; j += p) seg[j - l] = true;
        if (strt == p) seg[p - l] = false;
    }
    if (l == 1) seg[0] = true;
    int cnt = 0;
    for (int i = 0; i < len; i++) if (!seg[i]) cnt++;
    return cnt;
}

void solve(int T)
{
    int64_t l, r;

    cin >> l >> r;
    cout << "Case " << T << ": " << segSiv(l, r) << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    gen_p();
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}