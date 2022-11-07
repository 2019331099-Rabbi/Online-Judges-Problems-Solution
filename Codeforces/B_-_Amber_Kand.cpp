#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

string s1, s2;

bool check()
{
    if (s1.size() != s2.size()) return false;
    if (s1 == s2) return true;

    vector <char> ch1, ch2, ch3, ch4;
    int len = s1.size();
    for (int i = 0; i < len; i++) {
        if ((s1[i] - 'a') % 2 == 0) ch1.push_back(s1[i]);
        else ch2.push_back(s1[i]);
    }
    for (int i = 0; i < len; i++) {
        if ((s2[i] - 'a') % 2 == 0) ch3.push_back(s2[i]);
        else ch4.push_back(s2[i]);
    }
    return ch1 == ch3 && ch2 == ch4;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    cin >> s1 >> s2;
    if (check()) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}