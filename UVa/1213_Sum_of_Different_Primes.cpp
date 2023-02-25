#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1125
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

bool siv[sz + 1];
vector <int> primes;
int w, k, memo[191][1121][15];

void init()
{
    memset(memo, -1, sizeof(memo));
}

void gen_p()
{
    for (int i = 3; i * i <= sz; i += 2) {
        if (!siv[i]) {
            for (int j = i * i; j <= sz; j += i + i) siv[j] = true;
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= sz; i += 2) if (!siv[i]) primes.push_back(i);
}

int coinChange(int pos, int amount, int cnt)
{
    if (cnt == k) return amount == 0;
    if (amount < 0) return 0;
    if (primes[pos] > w) return (amount == 0 && cnt == k);
    if (memo[pos][amount][cnt] != -1) return memo[pos][amount][cnt];

    int val = 0;
    val += coinChange(pos + 1, amount, cnt);
    val += coinChange(pos + 1, amount - primes[pos], cnt + 1);
    return memo[pos][amount][cnt] = val;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    gen_p();
    while (cin >> w >> k && (w || k)) {
        init();
        cout << coinChange(0, w, 0) << endl;
    }
    return 0;
}