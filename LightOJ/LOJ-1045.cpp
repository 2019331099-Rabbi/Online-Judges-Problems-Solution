#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

double str[1000010];

void ff1()
{
    int i;
    for (i=1; i<1000001; i++) str[i]=str[i-1]+log10(i);
}

int main()
{
    RUN_FAST;
    ff1();
    int T, n, base, i;
    double sum;
    cin >> T;
    for (i=1; i<=T; i++) {
        cin >> n >> base;
        cout << "Case " << i << ": ";
        sum=str[n];
        if (base!=10) sum=sum/log10(base);
        cout << (int)sum+1 << endl;
    }
    return 0;
}
