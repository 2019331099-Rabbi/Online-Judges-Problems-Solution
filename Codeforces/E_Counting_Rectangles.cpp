#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1001
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int64_t upper(vector <pair <int64_t, int64_t>> pr, int64_t n, int64_t a, int64_t b)
// {
//     int64_t i = 0, j = n - 1, ans = n;
//     while (i <= j) {
//         int64_t mid = (i + j) >> 1;
//         if (pr[mid].first > a && pr[mid].second > b) {
//             ans = mid;
//             j = mid - 1;
//         }
//         else i = mid + 1;
//     }
//     return ans;
// }

// int64_t lower(vector <pair <int64_t, int64_t>> pr, int64_t n, int64_t a, int64_t b)
// {
//     int64_t i = 0, j = n - 1, ans = n;
//     while (i <= j) {
//         int64_t mid = (i + j) >> 1;
//         if (pr[mid].first > a && pr[mid].second > b) {
//             ans = mid;
//             j = mid - 1;
//         }
//         else i = mid + 1;
//     }
// }

void solve()
{
    // int64_t upper(vector <pair <int64_t, int64_t>> pr, int64_t n, int64_t a, int64_t b)
// {
//     int64_t i = 0, j = n - 1, ans = n;
//     while (i <= j) {
//         int64_t mid = (i + j) >> 1;
//         if (pr[mid].first > a && pr[mid].second > b) {
//             ans = mid;
//             j = mid - 1;
//         }
//         else i = mid + 1;
//     }
//     return ans;
// }

// int64_t lower(vector <pair <int64_t, int64_t>> pr, int64_t n, int64_t a, int64_t b)
// {
//     int64_t i = 0, j = n - 1, ans = n;
//     while (i <= j) {
//         int64_t mid = (i + j) >> 1;
//         if (pr[mid].first > a && pr[mid].second > b) {
//             ans = mid;
//             j = mid - 1;
//         }
//         else i = mid + 1;
//     }
// }
// int64_t upper(vector <pair <int64_t, int64_t>> pr, int64_t n, int64_t a, int64_t b)
// {
//     int64_t i = 0, j = n - 1, ans = n;
//     while (i <= j) {
//         int64_t mid = (i + j) >> 1;
//         if (pr[mid].first > a && pr[mid].second > b) {
//             ans = mid;
//             j = mid - 1;
//         }
//         else i = mid + 1;
//     }
//     return ans;
// }

// int64_t lower(vector <pair <int64_t, int64_t>> pr, int64_t n, int64_t a, int64_t b)
// {
//     int64_t i = 0, j = n - 1, ans = n;
//     while (i <= j) {
//         int64_t mid = (i + j) >> 1;
//         if (pr[mid].first > a && pr[mid].second > b) {
//             ans = mid;
//             j = mid - 1;
//         }
//         else i = mid + 1;
//     }
// }
// int64_t upper(vector <pair <int64_t, int64_t>> pr, int64_t n, int64_t a, int64_t b)
// {
//     int64_t i = 0, j = n - 1, ans = n;
//     while (i <= j) {
//         int64_t mid = (i + j) >> 1;
//         if (pr[mid].first > a && pr[mid].second > b) {
//             ans = mid;
//             j = mid - 1;
//         }
//         else i = mid + 1;
//     }
//     return ans;
// }

// int64_t lower(vector <pair <int64_t, int64_t>> pr, int64_t n, int64_t a, int64_t b)
// {
//     int64_t i = 0, j = n - 1, ans = n;
//     while (i <= j) {
//         int64_t mid = (i + j) >> 1;
//         if (pr[mid].first > a && pr[mid].second > b) {
//             ans = mid;
//             j = mid - 1;
//         }
//         else i = mid + 1;
//     }
// }
// int64_t upper(vector <pair <int64_t, int64_t>> pr, int64_t n, int64_t a, int64_t b)
// {
//     int64_t i = 0, j = n - 1, ans = n;
//     while (i <= j) {
//         int64_t mid = (i + j) >> 1;
//         if (pr[mid].first > a && pr[mid].second > b) {
//             ans = mid;
//             j = mid - 1;
//         }
//         else i = mid + 1;
//     }
//     return ans;
// }

// int64_t lower(vector <pair <int64_t, int64_t>> pr, int64_t n, int64_t a, int64_t b)
// {
//     int64_t i = 0, j = n - 1, ans = n;
//     while (i <= j) {
//         int64_t mid = (i + j) >> 1;
//         if (pr[mid].first > a && pr[mid].second > b) {
//             ans = mid;
//             j = mid - 1;
//         }
//         else i = mid + 1;
//     }
// }
    int64_t n, q;
    cin >> n >> q;
    vector<vector<int64_t>> v(sz);
    vector<vector<int64_t>> a(sz);

    for (int64_t i = 0; i < n; i++) {
        int64_t x, y;
        cin >> x >> y;
        v[x].push_back(y);
    }
    for (int64_t i = 1; i < sz; i++) sort(v[i].begin(), v[i].end());
    for (int64_t i = 1; i <= 1000; i++) for (int64_t j = 0; j < v[i].size(); j++) a[i].push_back(v[i][j]);
    for (int64_t i = 1; i <= 1000; i++) for (int64_t j = 1; j < v[i].size(); j++) a[i][j] += a[i][j - 1];
    while (q--) {
        int64_t a1, a2, a3, a4;
        cin >> a1 >> a2 >> a3 >> a4;
        int64_t ans = 0;
        for (int64_t i = a1 + 1; i < a3; i++) {
            int64_t tmp1 = upper_bound(v[i].begin(), v[i].end(), a2) - v[i].begin();
            int64_t tmp2 = lower_bound(v[i].begin(), v[i].end(), a4) - v[i].begin();
            tmp2--;
            if (tmp2 >= 0) ans += (i * (a[i][tmp2] - (tmp1 ? a[i][tmp1 - 1] : 0)));
        }
        cout << ans << endl;
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