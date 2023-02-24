#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 70005
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

bool siv[sz+10];
vector <int64_t> primes;

void gen_p()
{
    int64_t i, j, limit = sqrt(sz + 1);
    for (i = 3; i <= limit; i += 2) {
        if (!siv[i]) {
            for (j= i*i; j <= sz; j += i + i)
                siv[j] = true;
        }
    }
    primes.push_back(2);
    for (i = 3; i <= sz; i += 2)
        if (!siv[i]) primes.push_back(i);
}

void facotrs(int64_t n)
{
    vector < pair <int64_t, int64_t>> facts;
    for (int64_t i = 0; primes[i] * primes[i] <= n; i++) {
        int64_t tmp=primes[i];
        int64_t cnt=0;
        while (n%tmp==0) {
            n/=tmp;
            cnt++;
        }
        if (cnt >= 1) facts.push_back({tmp, cnt});
        if (n==1) break;
    }
    if (n>1) facts.push_back({n, 1});

    vector <int64_t> ans;
    ans.push_back(1);
    for (auto xx: facts) {
        int64_t p = xx.first;
        int64_t cnt = xx.second;

        vector <int64_t> tmp;
        int64_t initial = 1;
        for (int64_t i = 0; i <= cnt; i++) {
            if (i & 1) for (int64_t i = ans.size() - 1; i >= 0; i--) tmp.push_back(ans[i] * initial);
            else for (int64_t i = 0; i < ans.size(); i++) tmp.push_back(ans[i] * initial);
            initial *= p;
        }
        ans = tmp;
    }
    for (auto xx: ans) cout << xx << ' ';
    cout << endl;

}

void solve(int64_t T)
{
    int64_t n;
    cin >> n;
    cout << "Case " << T << ':' << endl;
    facotrs(n);
}

int main()
{
    RUN_FAST;
    gen_p();
    int64_t T;
    cin >> T;
    for (int64_t i = 1; i <= T; i++) solve(i);
    return 0;
}
