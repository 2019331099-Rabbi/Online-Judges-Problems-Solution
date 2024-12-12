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
    string a, b, c, d;

    cin >> a >> b >> c >> d;

    vector <vector <int>> v1(10), v2(10);

    if (a.size() < b.size()) {

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) v1[i].push_back(j);
        }
    }
    else {
        int l = a[0] - '0', r = b[0] - '0';
        for (int i = l; i <= r; i++) v1[0].push_back(i);
    }

    int len = min(a.size(), b.size());
    for (int i = 1; i <)

}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}