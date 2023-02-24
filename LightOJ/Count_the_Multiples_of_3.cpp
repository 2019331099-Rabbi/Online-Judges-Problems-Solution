#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
// #define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

struct info
{
    int64_t prop, mod2, mod1;
}tree[sz * 3];

void push(int node, int l, int r)
{
    if (tree[node].prop == 0) return;

    int mod = tree[node].prop % 3;
    int64_t mod0 = (r - l + 1) - (tree[node].mod1 + tree[node].mod2);

    if (mod == 1) {
        tree[node].mod2 = tree[node].mod1;
        tree[node].mod1 = mod0;
    }
    else if (mod == 2) {
        tree[node].mod1 = tree[node].mod2;
        tree[node].mod2 = mod0;
    }

    if (l != r) {
        tree[node * 2].prop += tree[node].prop;
        tree[node * 2 + 1].prop += tree[node].prop;
    }
    tree[node].prop = 0;
}

int64_t combine(int64_t lcResult, int64_t rcResult)
{
    return lcResult + rcResult;
}

void pull(int node)
{
    int a = node << 1;//Left child: node * 2
    int b = (node << 1) | 1;//Right child: (node * 2) + 1
    tree[node].mod1 = combine(tree[a].mod1, tree[b].mod1);
    tree[node].mod2 = combine(tree[a].mod2, tree[b].mod2);
}

void update(int node, int l, int r, int x, int y, int64_t val)
{
    push(node, l, r);
    if (r < x || l > y) return;
    if (l >= x && r <= y) {
        tree[node].prop += val;
        push(node, l, r);
        return;
    }

    int a = node << 1;//Left child: node * 2
    int b = (node << 1) | 1;//Right child: (node * 2) + 1
    int m = (l + r) >> 1;

    update(a, l, m, x, y, val);
    update(b, m + 1, r, x, y, val);
    pull(node);//Update the node with it's left child and right child
}

int64_t query(int node, int l, int r, int x, int y)
{
    push(node, l, r);
    if (r < x || l > y) return 0;
    if (l >= x && r <= y) return tree[node].mod1 + tree[node].mod2;

    int a = node * 2;
    int b = a + 1;
    int m = (l + r) >> 1;
    return combine(query(a, l, m, x, y), query(b, m + 1, r, x, y));
}

void solve(int T)
{
    cout << "Case " << T << ':' << endl;
    int n, q;

    cin >> n >> q;
    while (q--) {
        int c, a, b;
        cin >> c >> a >> b;
        a++, b++;
        if (c) cout << (b - a + 1) - query(1, 1, n, a, b) << endl;
        else update(1, 1, n, a, b, 1);
    }
    memset(tree, 0, sizeof(tree));
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}