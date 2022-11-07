#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 50000
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

bool siv[sz+1];
vector <int64_t> primes;

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
    for (i=3; i<=sz; i+=2)
        if (!siv[i]) primes.push_back(i);
}

int64_t segsiv(int64_t l, int64_t r)
{
    int64_t i, j, limit=sqrt(r+1), tmp1, tmp2, tmp=r-l+1;
    bool seg[tmp]={false};
    for (i=0; primes[i]<=limit; i++) {
        tmp1=primes[i];
        tmp2=(l/tmp1)*tmp1;
        if (tmp2<l) tmp2+=tmp1;
        for (j=tmp2; j<=r; j+=tmp1) {
            seg[j-l]=true;
        }
        if (tmp1==tmp2) seg[tmp1-l]=false;
    }
    if (l==1) seg[0]=true;
    int64_t cnt = 0;
    for (i=0; i<tmp; i++) if (!seg[i]) cnt++;
    return cnt;
}

void solve(int64_t T)
{
    int64_t a, b;
    cin >> a >> b;
    cout << "Case " << T << ": " << segsiv(a, b) << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    gen_p();
    int64_t T;
    cin >> T;
    for (int64_t i = 1; i <= T; i++) solve(i);
    return 0;
}