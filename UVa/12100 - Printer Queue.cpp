#include <bits/stdc++.h>
#define endl '\n'
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T, n, mypos, pr, i, time;
    deque <pair <int, bool>> dq;
    vector <int> v;
    bool flag;
    cin >> T;
    while (T--) {
        time=0;
        cin >> n >> mypos;
        for (i=0; i<n; i++) {
            cin >> pr;
            v.push_back(pr);
            dq.push_back({pr, i==mypos});
        }
        sort(v.begin(), v.end(), greater <int>());
        i=0;
        while (i<n) {
            pr=dq.front().first;
            flag=dq.front().second;
            dq.pop_front();

            if (pr==v[i]) {
                time++, i++;
                if (flag) break;
            }
            else dq.push_back({pr, flag});
        }
        cout << time << endl;
        v.clear(), dq.clear();
    }
    return 0;
}
