#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int main()
{
    RUN_FAST; cin.tie(nullptr);
    string s;
    int len;

    cin >> s;
    len = s.size();
    int64_t arr[len] = {0};

    for (int i = 1; i < len; i++) if (s[i] == s[i - 1] && s[i] == 'v') arr[i] = 1;
    for (int i = 1; i < len; i++) arr[i] += arr[i - 1];
    int64_t cnt = 0;
    for (int i = 1; i < len - 1; i++) if (s[i] == 'o') cnt += arr[i - 1] * (arr[len - 1] - arr[i]);
    cout << cnt << endl;

    return 0;
}