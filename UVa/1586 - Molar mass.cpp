#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 80
#define inf 1e8
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

double mass[sz];


int main()
{
    RUN_FAST; cin.tie(nullptr);
    mass['C']=12.01;
    mass['H']=1.008;
    mass['O']=16.00;
    mass['N']=14.01;
    int T, i, len, cnt, j;
    double sum;
    string s, tmps;
    cin >> T;
    while (T--) {
        cin >> s;
        sum=0;
        len=s.size();
        for (i=0; i<len; i++) {
            if (s[i]>='A') {
                tmps="";
                for (j=i+1; j<len; j++) {
                    if (s[j]>='A') break;
                    tmps+=s[j];
                }
                cnt=(tmps.size())?stoi(tmps):1;
                sum+=cnt*mass[s[i]];
                i=j-1;
            }
        }
        cout << fixed << setprecision(3);
        cout << sum << endl;
    }
    return 0;
}
