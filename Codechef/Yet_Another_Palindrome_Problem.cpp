#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 101
#define inf 100000000
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int64_t row4[]={0, 1, 0, -1};
// int64_t col4[]={1, 0, -1, 0};
 
//int64_t row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int64_t col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int64_t rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int64_t colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

bool isP(int64_t arr[], int64_t n)
{
    int64_t i = 0, j = n - 1;
    while (i < j) {
        if (arr[i] != arr[j]) return false;
        i++, j--;
    }
    return true;
}

bool isPossible(int64_t arr[], int64_t n)
{
    vector <int64_t> v;
    int64_t i = 0, j = n - 1;
    while (i < j) {
        if (arr[i] > arr[j]) return false;
        i++, j--;
    }

    i = 0, j = n - 1;
    while (i < j) {
        v.push_back(arr[j] - arr[i]);
        i++, j--;
    }
    for (int64_t i = 1; i < v.size(); i++) if (v[i - 1] < v[i]) return false;
    return true;
}

int64_t totSteps(int64_t arr[], int64_t n)
{
    int64_t i = 0, j = n - 1;
    int64_t carry = 0, ans = 0;

    while (i < j) {
        if (arr[i] == arr[j]) {
            i++, j--;
            continue;
        }
        arr[i] += carry;
        int64_t tmp = arr[j] - arr[i];
        i++, j--;
        if (tmp <= 0) continue;
        carry += tmp;
        ans += tmp;
    }
    return ans;
}

void solve()
{
    int64_t n;

    cin >> n;
    int64_t arr[n];
    for (int64_t i = 0; i < n; i++) cin >> arr[i];

    if (isP(arr, n)) cout << 0 << endl;
    else {
        if (isPossible(arr, n)) cout << totSteps(arr, n) << endl;
        else cout << -1 << endl;
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0; 
}