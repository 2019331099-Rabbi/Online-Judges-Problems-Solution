#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int nai(int occ[], int n)
{
    for (int i = 0; i <= n; i++) if (!occ[i]) return i;
    return -1;
}

void solve()
{
    int n;

    cin >> n;
    int occ[n + 1] = {0};
    queue <int> q;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        q.push(val);
        occ[val]++;
    }

    vector <int> ans;

    while (!q.empty()) {
        int nVal = nai(occ, n);
        set <int> st;
        for (int i = 0; i <= nVal; i++) st.insert(i);

        ans.push_back(nVal);
        while (st.size() > 1) {
            int val = q.front();
            q.pop();
            st.erase(val);
            occ[val]--;
        }
        if (nVal == 0) {
            if (!q.empty()) q.pop();
            while (!q.empty()) {
                q.pop();
                ans.push_back(nVal);
            }
        }
    }
    cout << ans.size() << endl;
    for (auto xx: ans) cout << xx << ' ';
    cout << endl;

}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}