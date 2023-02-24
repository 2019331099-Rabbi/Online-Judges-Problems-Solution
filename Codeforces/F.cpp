#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

/*
Problem link: https://cses.fi/problemset/task/1651/
*/
vector <pair <int, int>> tree(4 * sz, {0, 0});

void push(int node, int l, int r)
{
    if (tree[node].second == 0) return;

    tree[node].first += (r - l + 1) * tree[node].second;
    if (l != r) {
        tree[node * 2].second += tree[node].second;
        tree[node * 2 + 1].second += tree[node].second;
    }
    tree[node].second = 0;
}

int combine(int lcResult, int rcResult)
{
    return lcResult + rcResult;
}

void pull(int node)
{
    int a = node << 1;//Left child: node * 2
    int b = (node << 1) | 1;//Right child: (node * 2) + 1
    tree[node].first = combine(tree[a].first, tree[b].first);
}

void update(int node, int l, int r, int x, int y, int val)
{
    /*
    [l, r] -> Currently where we are
    [x, y] -> The range we want to update
    val -> The value we want to add with everyone in [x, y] range

    */
    push(node, l, r);//Update the secondagation value
    if (r < x || l > y) return;
    if (l >= x && r <= y) {
        tree[node].second += val;
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

int query(int node, int l, int r, int x, int y)
{
    push(node, l, r);
    if (r < x || l > y) return 0;
    if (l >= x && r <= y) return tree[node].first;

    int a = node * 2;
    int b = a + 1;
    int m = (l + r) >> 1;
    return combine(query(a, l, m, x, y), query(b, m + 1, r, x, y));
    //Combine the left child and right child result
}

void solve()
{
    int n, q;
 
    cin >> n >> q;
    
    int arr[n + 1];
    for (int i = 1; i <= n; i++) cin >> arr[i];
 
    while (q--) {
        int c;
        cin >> c;
        if (c == 2) {
            int k;
            cin >> k;
            int64_t cnt = query(1, 1, n, k, k);
            int val = arr[k];
            while (cnt--) {
                if (val < 9) break;
                int tmps = 0;
                while (val) {
                    tmps += val % 10;
                    val /= 10;
                }
                val = tmps;
            }
            cout << val << endl;
        }
        else {
            int a, b;
            cin >> a >> b;
            int64_t val = 1;
            update(1, 1, n, a, b, val);
        }
    }
    tree.clear();
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}