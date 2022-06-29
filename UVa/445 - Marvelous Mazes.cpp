#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 80
#define inf 1e8
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int main()
{
    RUN_FAST; cin.tie(nullptr);
    string s;
    int i, j, len, cnt;
    char ch;
    while (getline(cin, s)) {
        len=s.size();
        if (!len) {
            cout << endl;
            continue;
        }
        for (i=0; i<len; i++) {
            ch=s[i];
            if (ch=='!') {
                cout << endl;
                continue;
            }
            if (ch>='1' && ch<='9') {
                cnt=0;
                for (j=i; j<len; j++) {
                    ch=s[j];
                    if (ch>='A' || ch=='*') break;
                    cnt+=(ch-'0');
                }
                i=j;
                if (ch=='b') ch=' ';
                for (j=0; j<cnt; j++) cout << ch;
            }
        }
        cout << endl;
    }
    return 0;
}
