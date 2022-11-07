#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100000000
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int siv[sz / 32 + 2];
vector <long long int> primes;

bool Check(int N,int pos){return (bool)(N & (1<<pos));}
int Set(int N,int pos){	return N=N | (1<<pos);}

void gen_p()
{
    long long int i, j, limit=sqrt(sz+1);
    for (i=3; i<=limit; i+=2) {
        if (Check(siv[i / 32], i % 32) == 0) {
            for (j=i*i; j<=sz; j+=i+i)
                siv[j / 32]= Set(siv[j / 32], j % 32);
        }
    }
    primes.push_back(2);
    for (i=3; i<=sz; i+=2)
        if (Check(siv[i / 32], i % 32) == 0) primes.push_back(i);
}

void facotrs(long long int n)
{
    long long int limit = sqrt(n + 1), res = n, sum = 1;

    for (long long int i = 0; primes[i] <= limit; i++) {
        long long int p = primes[i];
        long long int cnt = 0;
        while (n % p==0) {
            n /= p;
            cnt++;
        }
        long long int tmps = pow(p, cnt + 1) + 0.5;
        sum *= (tmps - 1) / (p - 1);
        if (n==1) break;
    }
    if (n>1) {
        long long int tmps = pow(n, 2) + 0.5;
        sum *= (tmps - 1) / (n - 1);
    }
    printf("%lld\n", sum - res);
}

void solve()
{
    long long int n;
    scanf("%lld", &n);
    facotrs(n);
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    gen_p();
    long long int T;
    scanf("%lld", &T);
    while (T--) solve();
    return 0;
}