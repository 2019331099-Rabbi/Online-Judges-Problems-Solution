#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 400
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row4[]={0, 1, 0, -1};
// int col4[]={1, 0, -1, 0};
 
//int row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

bool siv[sz+1];
vector <int> primes;

void gen_p()
{
    int i, j, limit=sqrt(sz+1);
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

void solve()
{
    int a, b, c, d;

    cin >> a >> b >> c >> d;
    int n = a * b;

    int limit = sqrt(n+1);
    vector < pair <int, int> > facts;
    for (int i = 0; primes[i] <= limit; i++) {
        int tmp = primes[i];
        int cnt = 0;
        while (n % tmp == 0) {
            n /= tmp;
            cnt++;
        }
        facts.push_back({tmp, cnt});
        if (n == 1) break;
    }
    if (n > 1) facts.push_back({n, 1});

    
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