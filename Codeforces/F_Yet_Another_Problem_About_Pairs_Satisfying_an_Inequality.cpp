#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <pair <int, int>> pr;
int n;

int numberOfpairs(int left, int x)
{
    int right = pr.size() - 1, mid, ans = pr.size();

    while (left <= right) {
        mid = (left + right) >> 1;
        if (pr[mid].first <= x) left = mid + 1;
        else {
            ans = mid;
            right = mid - 1;
        }
    }
    return ans;
}

void solve()
{
    int val;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val;
        if (i > val) pr.push_back({val, i});
    }
    sort(pr.begin(), pr.end());
    int64_t cnt = 0;
    for (int i = 0; i < pr.size(); i++) {
        val = pr.size() - numberOfpairs(i, pr[i].second);
        cnt += val;
    }
    cout << cnt << endl;
    pr.clear();
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}