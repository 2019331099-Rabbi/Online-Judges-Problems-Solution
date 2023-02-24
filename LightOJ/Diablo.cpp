#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 180010
#define MX 150010
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
	int a = node << 1;
	int b = (node << 1) | 1;
	int m = (l + r) >> 1;

	init(a, l, m);
	init(b, m + 1, r);
	tree[node] = tree[a] + tree[b];
}

void update(int node, int l, int r, int x, int64_t val)
{
	if (r < x || l > x) return;
	if (l == r && l == x) {
		tree[node] = val;
		return;
	}
	int a = node << 1;
	int b = (node << 1) | 1;
	int m = (l + r) >> 1;

	update(a, l, m, x, val);
    update(b, m + 1, r, x, val);
	tree[node] = tree[a] + tree[b];
}

int64_t query(int node, int l, int r, int x, int y)
{
	if (r < x || l > y) return 0;
	if (l >= x && r <= y) return tree[node];
	
	int a = node << 1;
	int b = (node << 1) | 1;
	int m = (l + r) >> 1;
	return query(a, l, m, x, y) + query(b, m + 1, r, x, y);
}

int ac_pos(int64_t val)
{
    int64_t sum = query(1, 1, MX, 1, 4);
    int low = 1, high = MX;
    int ans = -1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        int64_t sum = query(1, 1, MX, 1, mid);
        if (sum < val) low = mid + 1;
        else {
            if (sum == val) ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

void solve(int T)
{
    cout << "Case " << T << ':' << endl;
    int n, q;

    cin >> n >> q;
    int64_t id[n + q + 1];
    for (int i = 1; i <= n; i++) {
        cin >> id[i];
        // update(1, 1, MX, i, 1);
    }

    for (int i = 1; i <= n; i++) arr[i] = 1;
    init(1, 1, MX);

    while (q--) {
        char ch;
        int64_t val;
        cin >> ch >> val;
        if (ch == 'a') {
            id[++n] = val;
            update(1, 1, MX, n, 1);
        }
        else {
            int ans = ac_pos(val);
            if (ans == -1) cout << "none" << endl;
            else {
                cout << id[ans] << endl;
                id[ans] = 0;
                update(1, 1, MX, ans, 0);
            }
        }
    }
    memset(tree, 0, sizeof(tree));
    memset(arr, 0, sizeof(arr));
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}