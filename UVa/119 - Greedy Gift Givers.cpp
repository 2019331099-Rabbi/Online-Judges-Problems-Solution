#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 1000000
#define inf 1e8
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n, i, tmp, amnt, p;
    bool flag=false;
    string from, to;
    map <string, int> mp;
    while (cin >> n) {
        if (flag) cout << endl;
        flag=true;
        vector <string> name(n);
        for (i=0; i<n; i++) {
            cin >> name[i];
            mp[name[i]]=i;
        }
        vector <int> gain(n), lose(n);
        for (i=0; i<n; i++) {
            cin >> from >> amnt >> p;
            if (!p) continue;
            tmp=amnt/p;
            lose[mp[from]]+=(tmp*p);
            while (p--) {
                cin >> to;
                gain[mp[to]]+=tmp;
            }
        }
        for (i=0; i<n; i++) {
            tmp=mp[name[i]];
            gain[tmp]-=lose[tmp];
            cout << name[i] << ' ' << gain[tmp] << endl;
        }
        mp.clear();
    }
    return 0;
}
