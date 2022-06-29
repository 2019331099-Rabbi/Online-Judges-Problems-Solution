#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 5
#define inf 1e8
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int values[]={1, 10, 100, 1000, 10000};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n, m, sum1, sum2, sum, tot, dead, i, val;
    while (cin >> n >> m) {
        sum1=sum2=0;
        while (m--) {
            cin >> tot >> dead;
            sum=0;
            for (i=1; i<n; i++) cin >> val, sum+=val;
            if (sum>=tot) continue;
            if (sum+dead<=tot) sum1+=dead;
            for (i=0; i<sz; i++) if (sum+values[i]>tot) break;
            sum2+=values[i-1];
        }
        cout << sum2-sum1 << endl;
    }
    return 0;
}
