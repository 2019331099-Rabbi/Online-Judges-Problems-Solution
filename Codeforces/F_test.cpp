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

struct info
{
    int sum, prop;
};

void push(int node, int l, int r, info tree[])
{
    if (tree[node].prop == 0) return;

    tree[node].sum += (r - l + 1) * tree[node].prop;
    if (l != r) {
        tree[node * 2].prop += tree[node].prop;
        tree[node * 2 + 1].prop += tree[node].prop;
    }
    tree[node].prop = 0;
}

int combine(int lcResult, int rcResult)
{
    return lcResult + rcResult;
}

void pull(int node, info tree[])
{
    int a = node << 1;//Left child: node * 2
    int b = (node << 1) | 1;//Right child: (node * 2) + 1
    tree[node].sum = combine(tree[a].sum, tree[b].sum);
}

void update(int node, int l, int r, int x, int y, int val, info tree[])
{
    /*
    [l, r] -> Currently where we are
    [x, y] -> The range we want to update
    val -> The value we want to add with everyone in [x, y] range

    */
    push(node, l, r, tree);//Update the propagation value
    if (r < x || l > y) return;
    if (l >= x && r <= y) {
        tree[node].prop += val;
        push(node, l, r, tree);
        return;
    }

    int a = node << 1;//Left child: node * 2
    int b = (node << 1) | 1;//Right child: (node * 2) + 1
    int m = (l + r) >> 1;

    update(a, l, m, x, y, val, tree);
    update(b, m + 1, r, x, y, val, tree);
    pull(node, tree);//Update the node with it's left child and right child
}

int query(int node, int l, int r, int x, int y, info tree[])
{
    push(node, l, r, tree);
    if (r < x || l > y) return 0;
    if (l >= x && r <= y) return tree[node].sum;

    int a = node * 2;
    int b = a + 1;
    int m = (l + r) >> 1;
    return combine(query(a, l, m, x, y, tree), query(b, m + 1, r, x, y, tree));
    //Combine the left child and right child result
}

void solve()
{
    int n, q;
 
    cin >> n >> q;
    struct info tree[3 * n] = {0};
    int arr[n + 1];
    for (int i = 1; i <= n; i++) cin >> arr[i];
 
    while (q--) {
        int c;
        cin >> c;
        if (c == 2) {
            int k;
            cin >> k;
            int64_t cnt = query(1, 1, n, k, k, tree);
            int val = arr[k];
            while (cnt--) {
                if (val < 9) break;
                int sum = 0;
                while (val) {
                    sum += val % 10;
                    val /= 10;
                }
                val = sum;
            }
            arr[k] = val;
            int64_t tmp = -1;
            update(1, 1, n, k, k, tmp, tree);
            cout << val << endl;
        }
        else {
            int a, b;
            cin >> a >> b;
            int64_t val = 1;
            update(1, 1, n, a, b, val, tree);
        }
    }
}


int main()
{
    RUN_FAST; cin.tie(nullptr);




    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}