#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

string s;

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int len, tmp;

    cin >> s;
    len = s.size();

    int64_t cnt = ((s[0] - '0') % 4 == 0)?1:0;
    for (int i = 1; i < len; i++) {
        tmp = s[i] - '0';
        if (tmp % 4 == 0) cnt++;
        tmp += 10 * (s[i - 1] - '0');
        if (tmp % 4 == 0) cnt += i;
    }
    cout << cnt << endl;
    return 0;
}