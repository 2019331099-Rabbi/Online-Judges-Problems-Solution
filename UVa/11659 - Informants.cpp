#include <bits/stdc++.h>
#define endl '\n'
#define sz 26
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n, q, a, b, cnt;
    while (cin >> n >> q && (n || q)) {
        bool reliable[n+1];
        memset(reliable, true, sizeof(reliable));
        cnt=0;
        while (q--) {
            cin >> a >> b;
            if (b<0) {
                b*=-1;
                if (reliable[b]) cnt++, reliable[b]=false;
            }
        }
        cout << n-cnt << endl;
    }
    return 0;
}
