#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int main()
{
    RUN_FAST; cin.tie(nullptr);

    string s1, s2;

    cin >> s1 >> s2;
    int len = min(s1.size(), s2.size());
    bool flag = true;

    for (int i = 0; i < len; i++) {
        if (s1[i] == s2[i]) continue;
        if (s1[i] > s2[i]) cout << s1 << endl;
        else cout << s2 << endl;
        flag = false;
        break;
    }

    if (flag) {
        if (len == s1.size()) cout << s2 << endl;
        else cout << s1 << endl;
    }
    return 0;
    
}