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

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n, m;
    string s;

    cin >> n >> m;

    int ans[m] = {0};
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) if (s[j] == '#') ans[j]++;
    }
    for (int i = 0; i < m; i++) cout << ans[i] << ' ';
    cout << endl;
    return 0;
    
}