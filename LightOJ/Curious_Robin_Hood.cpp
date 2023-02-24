#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100000
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int64_t tree[3 * sz], arr[sz];

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

void update(int node, int l, int r, int x, int64_t val)
{
	if (r < x || l > x) return;
	if (l == r && l == x) {
		tree[node] = val;
        arr[l] = val;
		return;
	}
	int a = node * 2;
	int b = a + 1;
	int m = (l + r) / 2;

	update(a, l, m, x, val);
    update(b, m + 1, r, x, val);
	tree[node] = tree[a] + tree[b];
}

int64_t query(int node, int l, int r, int x, int y)
{
	if (r < x || l > y) return 0;
	if (l >= x && r <= y) return tree[node];
	
	int a = node * 2;
	int b = a + 1;
	int m = (l + r) / 2;
	return query(a, l, m, x, y) + query(b, m + 1, r, x, y);
}

void solve(int T)
{
    int n, q;

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    init(1, 1, n);

    cout << "Case " << T << ":" << endl;
    while (q--) {
        int c;
        cin >> c;
        if (c == 1) {
            int x;
            cin >> x;
            cout << arr[x + 1] << endl;
            update(1, 1, n, x + 1, 0);
            
        }
        else if (c == 2) {
            int x, val;
            cin >> x >> val;
            update(1, 1, n, x + 1, arr[x + 1] + val);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << query(1, 1, n, a + 1, b + 1) << endl;
        }
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}