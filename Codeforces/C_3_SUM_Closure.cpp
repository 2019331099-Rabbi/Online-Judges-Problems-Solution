                    #include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int n;
vector <int64_t> pos, neg;

bool isPossible(int zero)
{
    if (pos.size() > 2 || neg.size() > 2) return false;

    for (auto xx: neg) pos.push_back(xx);
    if (zero) pos.push_back(0);

    n = pos.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i == j || j == k || i == k) continue;
                int val = pos[i] + pos[j] + pos[k];
                bool isPresent = false;
                for (auto xx: pos)
                    if (val == xx) {
                        isPresent = true;
                        break;
                    }
                if (!isPresent) return false;
            }
        }
    }
    return true;
}

void solve()
{
    cin >> n;

    int zero = 0;
    for (int i = 0; i < n; i++) {
        int64_t val;
        cin >> val;
        if (!val) zero++;
        else if (val > 0) pos.push_back(val);
        else neg.push_back(val);
    }
    if (isPossible(zero)) cout << "YES" << endl;
    else cout << "NO" << endl;
    pos.clear();
    neg.clear();
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int64_t T;
    cin >> T;
    while (T--) solve();
    return 0;
}