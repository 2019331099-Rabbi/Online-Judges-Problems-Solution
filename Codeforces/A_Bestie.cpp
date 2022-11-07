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

int findGCD(int arr[], int n)
{
    int gcd = arr[1];
    for (int i = 1; i <= n; i++) gcd = __gcd(gcd, arr[i]);
    return gcd;
}

void solve()
{
    int n;

    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    if (findGCD(arr, n) == 1) cout << 0 << endl;
    else {
        int res = arr[n];
        arr[n] = __gcd(n, arr[n]);
        if (findGCD(arr, n) == 1) {
            cout << 1 << endl;
            return;
        }
        arr[n] = res;
        
        arr[n - 1] = __gcd(n - 1, arr[n - 1]);
        if (findGCD(arr, n) == 1) {
            cout << 2 << endl;
            return;
        }
        cout << 3 << endl;
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