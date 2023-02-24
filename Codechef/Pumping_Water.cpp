#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;
 
int64_t arr[sz];

struct info
{
    int64_t mn, pos;
}tree[sz * 3];
 
void rmq(int node, int l, int r)
{
	if (l == r) {
		tree[node].mn = arr[l];
        tree[node].pos = l;
		return;
	}
	int a = node << 1;
	int b = (node << 1) | 1;
	int m = (l + r) >> 1;
 
	rmq(a, l, m);
	rmq(b, m + 1, r);

    if (tree[a].mn > tree[b].mn) tree[node].mn = tree[a].mn, tree[node].pos = tree[a].pos;
    else tree[node].mn = tree[b].mn, tree[node].pos = tree[b].pos;
}
 
pair <int, int> query(int node, int l, int r, int x, int y)
{
	if (r < x || l > y) return {INT_MIN, -1};
	if (l >= x && r <= y) return {tree[node].mn, tree[node].pos};
 
	int a = node << 1;
	int b = (node << 1) | 1;
	int m = (l + r) >> 1;

    auto pr1 = query(a, l, m, x, y);
    auto pr2 = query(b, m + 1, r, x, y);

    if (pr1.first > pr2.first) return pr1;
    else return pr2;
}

int64_t minres(int n, int l, int r)
{
    auto pr = query(1, 1, n, l, r);
    if (pr.second == l || pr.second == r) return 1;

    int64_t mn1 = minres(n, l, pr.second - 1);
    int64_t mn2 = minres(n, pr.second + 1, r);
    return 1 + min(mn1, mn2);
}

void solve()
{
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++) tree[i].mn = tree[i].pos = -1;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    rmq(1, 1, n);
    cout << minres(n, 1, n) << endl;
}
 
int main()
{
    RUN_FAST; cin.tie(nullptr);
	int T;
    cin >> T;
    while (T--) solve();
    return 0;
}