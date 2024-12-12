#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int points[sz][sz];

void init()
{
    for (int i = 0; i < 5; i++) {
        for (int j = i; j < sz - i; j++) {
            points[i][j] = i + 1, points[sz - i - 1][j] = i + 1;
            points[j][i] = i + 1, points[j][sz - i - 1] = i + 1;
        }
    }
}

void solve(int T)
{
    vector <string> vs;

    int n = 10;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vs.push_back(s);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vs[i][j] == 'X') sum += points[i][j];
        }
    }
    cout << sum << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    init();
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}