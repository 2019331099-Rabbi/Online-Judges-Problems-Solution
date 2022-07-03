#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 110
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

string s;
int len;

int div8()
{
    int tmp;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            for (int k = j + 1; k < len; k++) {
                tmp = s[k] - '0';
                tmp += (s[j] - '0') * 10;
                tmp += (s[i] - '0') * 100;
                if (tmp % 8 == 0) return tmp;
            }
        }
    }
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            tmp = s[j] - '0';
            tmp += (s[i] - '0') * 10;
            if (tmp % 8 == 0) return tmp;
        }
    }
    for (int i = 0; i < len; i++) if (s[i] == '0' || s[i] == '8') return s[i] - '0';
    return -1;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    cin >> s;
    len = s.size();

    int ans = div8();
    if (ans == -1) cout << "NO" << endl;
    else cout << "YES" << endl << ans << endl;
    return 0;
}