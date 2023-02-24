#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100000000
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;
 
bool siv[sz];
vector <int64_t> primes;

void gen_p()
{
    for (int i = 3; i * i <= sz; i += 2) {
        if (!siv[i]) {
            for (int j = i * i; j <= sz; j += i + i)
                siv[j] = 1;
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= sz; i += 2)
        if (!siv[i]) primes.push_back(i);
    primes.push_back(100000007);
}

int64_t Pow(int64_t b, int64_t p)
{
    if (p == 0) return 1;
    if (p & 1) return b * Pow(b, p - 1);
    int64_t tmp = Pow(b, p / 2);
    return tmp * tmp;
}

void factors(int64_t n)
{
    int64_t sum = 1, tmpn = n;
    for (int i = 0; primes[i] * primes[i] <= n; i++) {
        int64_t p = primes[i];
        int64_t cnt = 0;
        if (n % p == 0) {
            while (n % p == 0) cnt++, n /= p;
            int64_t tmps = Pow(p, cnt + 1);
            sum *= (tmps - 1) / (p - 1);
        }
    }
    if (n > 1) sum *= (n + 1);
    cout << sum - tmpn << endl;
}

void solve()
{
    int64_t n;
    cin >> n;
    factors(n);
}
 
int main()
{
    RUN_FAST; cin.tie(nullptr);
    gen_p();
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
} 