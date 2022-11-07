#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row4[]={0, 1, 0, -1};
// int col4[]={1, 0, -1, 0};
 
//int row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

int par[sz], rep[sz];

void init()
{
    for (int i = 0; i < sz; i++) par[i] = i, rep[i] = -1;
}

int find_set(int u)
{
    return (par[u]==u)?u:par[u]=find_set(par[u]);
}

void solve()
{
    init();
    int n;
    string s;

    cin >> n >> s;

    int cnt = 0;

    for (auto xx: s) {
        if (rep[xx - 'a'] != -1) continue;
        int u = find_set(xx - 'a');
        int v;
        for (v = 0; v < sz; v++) {
            if (par[v] == v && (u != v || cnt >= 25)) {
                par[v] = xx - 'a';
                rep[xx - 'a'] = v;
                break;
            }
        }
        cnt++;
    }
    for (auto xx: s) {
        char ch = 'a' + rep[xx - 'a'];
        cout << ch;
    }
    cout << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0; 
}