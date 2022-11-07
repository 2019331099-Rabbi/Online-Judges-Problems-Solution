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
    string s;

    cin >> n >> s;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int left = 0;
    while (s[left] != '1' && left < n) left++;
    int right = left + 1;

    int ans = 0;
    n++;
    s += '0';
    while (right < n) {
        if (s[right] == '1') {
            right++;
            continue;
        }
        int sum = 0;
        for (int i = left; i < right; i++) sum += arr[i];
        if (left > 0) {
            int mn = INT_MAX;
            for (int i = left - 1; i < right; i++) mn = min(mn, arr[i]);
            sum = max(sum, sum - mn + arr[left - 1]);
        }
        ans += sum;
        left = right;
        while (s[left] != '1' && left < n) left++;
        right = left + 1;
    }
    cout << ans << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0; 
}