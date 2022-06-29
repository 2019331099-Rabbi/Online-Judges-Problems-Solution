#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 1001
#define inf 1e8
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

string s;
char ch;

void ff1()
{
    stack <int> stk;
    int i, len=s.size(), cnt=0;
    for (i=0; i<len; i++) {
        ch=s[i];
        if (s[i]=='\\') {
            stk.push(i);
            continue;
        }
        else if (ch=='/' && !stk.empty()) {
            cnt+=i-stk.top();
            stk.pop();
        }
    }
    cout << cnt << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        ff1();
    }
    return 0;
}
