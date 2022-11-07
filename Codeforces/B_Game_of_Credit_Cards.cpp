#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int n;
string s1, s2;

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int i, j;
    cin >> n >> s1 >> s2;

    int digits[sz] = {0};
    for (i = 0; i < n; i++) digits[s2[i] - '0']++;

    int cnt = 0;
    for (i = 0; i < n; i++) {
        for (j = s1[i] - '0'; j < sz; j++) {
            if (digits[j]) {
                digits[j]--;
                break;
            }
        }
        if (j >= sz) cnt++;
    }
    cout << cnt << endl;

    for (i = 0; i < sz; i++) digits[i] = 0;
    for (i = 0; i < n; i++) digits[s2[i] - '0']++;

    cnt = 0;
    for (i = 0; i < n; i++) {
        for (j = s1[i] - '0' + 1; j < sz; j++) {
            if (digits[j]) {
                digits[j]--;
                break;
            }
        }
        if (j < sz) cnt++;
    }
    cout << cnt << endl;
    return 0;
}