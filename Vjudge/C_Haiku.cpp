#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void solve(int T)
{
    
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    vector <string> vs;

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',') s[i] = ' ';
    }
    cout << s << endl;

    return 0;
}