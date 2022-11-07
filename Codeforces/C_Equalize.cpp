#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int n;
string s1, s2;

int main()
{
    RUN_FAST; cin.tie(nullptr);
    cin >> n >> s1 >> s2;

    int cnt = 0, i = 0;
    while (i < n) {
        if (s1[i] == s2[i]) i++;
        else {
            if (s2[i] == s1[i + 1] && s2[i + 1] == s1[i]) i += 2;
            else i++;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}