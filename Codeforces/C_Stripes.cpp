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

vector <string> v;

void solve()
{
    
    string s;

    for (int i = 0; i < 8; i++) {
        cin >> s;
        v.push_back(s);
    }
    bool flag = true;
    for (int i = 0; i < 8; i++) {
        int cnt = 0;
        for (int j = 0; j < 8; j++) if (v[i][j] == 'R') cnt++;
        if (cnt == 8) {
            flag = false;
            cout << 'R' << endl;
            break;
        }
    }
    if (flag) cout << 'B' << endl;
    v.clear();

}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0; 
}