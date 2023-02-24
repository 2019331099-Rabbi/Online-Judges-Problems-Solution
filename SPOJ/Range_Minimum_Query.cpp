#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

struct info
{
    int64_t min, prop;
}tree[sz * 3];

int64_t arr[sz];

void init(int node, int l, int r)
{
    if (l == r) {
        tree[node].min = arr[l];
        return;
    }
    int a = node * 2;
    int b = a + 1;
    int m = (l + r) / 2;

    init(a, l, m);
    init(b, m + 1, r);
    tree[node].min = min(tree[a].min, tree[b].min);
}

void push(int node, int l, int r)
{
    if (tree[node].prop == 0) return;

    tree[node].min += tree[node].prop;
    if (l != r) {
        tree[node * 2].prop = tree[node * 2 + 1].prop = tree[node].prop;
    }
    tree[node].prop = 0;
}

void update(int node, int l, int r, int x, int y, int64_t val)
{
    push(node, l, r);

    if (r < x || l > y) return;
    if (l >= x && r <= y) {
        tree[node].min += val;
        tree[node * 2].prop += val;
        tree[node * 2 + 1].prop += val;
        return;
    }

    int a = node * 2;
    int b = a + 1;
    int m = (l + r) / 2;

    update(a, l, m, x, y, val);
    update(b, m + 1, r, x, y, val);
    tree[node].min = min(tree[a].min, tree[b].min);
}

int64_t query(int node, int l, int r, int x, int y)
{
    push(node, l, r);
    if (r < x || l > y) return INT64_MAX;
    if (l >= x && r <= y) return tree[node].min;

    int a = node * 2;
    int b = a + 1;
    int m = (l + r) / 2;
    return min(query(a, l, m, x, y), query(b, m + 1, r, x, y));
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n, q;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    init(1, 1, n);

    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << query(1, 1, n, a + 1, b + 1) << endl;
    }
    return 0;
}
/*
8 1
-1 2 4 1 7 1 3 2
1 1 4 3
1 1 4 1
1 1 1 2
2 4 5
*/