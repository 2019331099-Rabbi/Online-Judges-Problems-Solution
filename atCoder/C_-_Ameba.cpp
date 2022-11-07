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
    int n;

    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) cin >> arr[i];

    int par[2 * n + 10], len = 2 * n + 1;

    par[1] = 0;
    for (int i = 1; i <= n; i++) {
        int c1 = 2 * i;
        int c2 = c1 + 1;
        par[c1] = par[c2] = arr[i];
    }

    // for (int i = 1; i <= len; i++) cout << par[i] << ' ';
    // cout << endl;

    int memo[len + 10] = {0};

    for (int i = 1; i <= len; i++) {
        int cnt = 0;
        int tmp = i;
        while (tmp != 1) {
            cnt++;
            tmp = par[tmp];
            if (memo[tmp]) {
                cnt += memo[tmp];
                break;
            }
        }
        memo[i] = cnt;

        cout << cnt << endl;
    }
    cout << endl;
}