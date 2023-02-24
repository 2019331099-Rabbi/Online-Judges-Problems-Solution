#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1125
#define inf 1e9 + 9
#define mod 100000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

bool siv[sz+1];
vector <int64_t> primes;
int64_t w, k, memo[191][1121][15];

void gen_p()
{
    int64_t i, j, limit=sqrt(sz+1);
    for (i=3; i<=limit; i+=2) {
        if (!siv[i]) {
            for (j=i*i; j<=sz; j+=i+i)
                siv[j]=true;
        }
    }
    primes.push_back(2);
    for (i=3; i<=sz; i+=2) if (!siv[i]) primes.push_back(i);
}

void init()
{
    memset(memo, -1, sizeof(memo));
}

int64_t coinChange(int64_t pos, int64_t amount, int64_t cnt)
{
    if (amount < 0) return 0;
    if (cnt == k && amount == 0) return 1;
    if (cnt == k) return amount == 0;
    if (primes[pos] > w) return (amount == 0 && cnt == k);
    if (memo[pos][amount][cnt] != -1) return memo[pos][amount][cnt];

    int64_t val = coinChange(pos + 1, amount, cnt);
    val += coinChange(pos + 1, amount - primes[pos], cnt + 1);
    return memo[pos][amount][cnt] = val;
}

void solve()
{
    init();
    cout << coinChange(0, w, 0) << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    gen_p();

    while (cin >> w >> k && (w || k)) solve();
    return 0;
}