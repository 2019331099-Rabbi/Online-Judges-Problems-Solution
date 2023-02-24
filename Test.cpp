#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int tree[3 * sz], arr[sz];

void init(int node, int l, int r)
{
	if (l == r) {
		tree[node] = arr[l];
		return;
	}
	int a = node * 2;
	int b = a + 1;
	int m = (l + r) / 2;

	init(a, l, m);
	init(b, m + 1, r);
	tree[node] = tree[a] + tree[b];
}

void update(int node, int l, int r, int x, int val)
{
	if (r < x || l > x) return;
	if (l == r && l == x) {
		tree[node] = val;
		return;
	}
	int a = node * 2;
	int b = a + 1;
	int m = (l + r) / 2;

	init(a, l, m);
	init(b, m + 1, r);
	tree[node] = tree[a] + tree[b];
}

int query(int node, int l, int r, int x, int y)
{
	if (r < x || l > y) return 0;
	if (l >= x && r <= y) return tree[node];

	int a = node * 2;
	int b = a + 1;
	int m = (l + r) / 2;
	return query(a, l, m, x, y) + query(b, m + 1, r, x, y);
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
	int n, q;

	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	init(1, 1, n);

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << query(1, 1, n, l, r) << endl;
	}
	return 0;
}