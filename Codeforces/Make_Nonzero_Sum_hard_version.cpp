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

void solve()
{
    int n;

    cin >> n;

    int arr[n + 1];
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    vector <pair <int, int>> ans;
    int i = 2;

    int prevsum = 0;
    while (i <= n) {
        if ((arr[i] == 1 && arr[i - 1] == -1) || (arr[i] == -1 && arr[i - 1] == 1)) ans.push_back({i - 1, i - 1}), ans.push_back({i, i});
        else if ((arr[i] == 1 && arr[i - 1] == 1) || (arr[i] == -1 && arr[i - 1] == -1)) ans.push_back({i - 1, i});
        else {
            if (prevsum >= 0) {
                if (arr[i - 1] == 0 && arr[i] == 1) ans.push_back({i - 1, i}), prevsum--;
                else if (arr[i - 1] == 0 && arr[i] == -1) ans.push_back({i - 1, i - 1}), ans.push_back({i, i}), prevsum--;
                else if (arr[i - 1] == 1 && arr[i] == 0) ans.push_back({i - 1, i - 1}), ans.push_back({i, i}), prevsum++;
                else if (arr[i - 1] == -1 && arr[i] == 0) ans.push_back({i - 1, i - 1}), ans.push_back({i, i}), prevsum--;
            }
            else if (prevsum < 0) {
                if (arr[i - 1] == 0 && arr[i] == 1) ans.push_back({i - 1, i - 1}), ans.push_back({i, i}), prevsum++;
                else if (arr[i - 1] == 0 && arr[i] == -1) ans.push_back({i - 1, i}), prevsum++;
                else if (arr[i - 1] == 1 && arr[i] == 0) ans.push_back({i - 1, i - 1}), ans.push_back({i, i}), prevsum++;
                else if (arr[i - 1] == -1 && arr[i] == 0) ans.push_back({i - 1, i - 1}), ans.push_back({i, i}), prevsum--;
            }
        }
        i += 2;
    }
    if (prevsum) cout << -1 << endl;
    else {
        if (ans.size() == 0) ans.push_back({1, n});
        cout << ans.size() << endl;
        for (auto xx: ans) cout << xx.first << ' ' << xx.second << endl;
    }
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0; 
}