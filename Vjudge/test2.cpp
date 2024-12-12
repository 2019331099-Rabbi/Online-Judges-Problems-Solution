#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

vector <int> g[N];
int t, cs = 0, n, m, x;

int call (int u) {
    cout << u << ' ';
    for (int v : g[u]) {
        if (call(v) == 0) return 1;
    }
    return 0;
}

int main (int argc, char const *argv[]) {
    scanf("%d", &t); while (t--) {
        scanf("%d %d %d", &n, &m, &x);
        while (m--) {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
        }
        printf("Case %d: %s\n", ++cs, call(x) ? "Yes" : "No");
        for (int i = 1; i <= n; ++i) g[i].clear();
    }
    return 0;
}