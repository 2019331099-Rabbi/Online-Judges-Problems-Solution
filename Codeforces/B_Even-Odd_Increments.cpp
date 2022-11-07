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

bool check(int arr[], int n, string &s)
{
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) if (arr[j] == arr[i] && s[j] != s[i]) return false;
    }
    return true;
}

void solve()
{
    int n, q;

    cin >> n >> q;
    int64_t sum = 0, odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        int64_t val;
        cin >> val;
        sum += val;
        if (val & 1) odd++;
        else even++;
    }
    while (q--) {
        bool flag;
        int val;
        cin >> flag >> val;
        if (flag) {
            sum += odd * val;
            if (val & 1) even += odd, odd = 0;
        }
        else {
            sum += even * val;
            if (val & 1) odd += even, even = 0;
        }
        cout << sum << endl;
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