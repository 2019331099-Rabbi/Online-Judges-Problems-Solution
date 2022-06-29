#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 10001
#define inf 1e9
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

map <string, int> mp;
vector <int> adj[sz];
int vis[sz];

void bfs(int u)
{
    queue <int> q;
    q.push(u);
    vis[u]=1;

    while (!q.empty()) {
        u=q.front();
        q.pop();
        for (int xx: adj[u]) {
            if (vis[xx]) continue;
            q.push(xx);
            vis[xx]=vis[u]+1;
        }
    }
}

void take_in(int n, int m)
{
    string s, tmp;
    vector <int> v;
    int i, j, len, val, cnt=1;

    while (n--) {
        getline(cin, s);
        len=s.size();

        tmp="";
        for (i=1; i<len; i++) {
            tmp+=s[i-1];
            if ((s[i]==',' && s[i-1]=='.') || s[i]==':') {
                val=mp[tmp];
                if (!val) {
                    mp[tmp]=cnt, val=cnt;
                    cnt++;
                }
                v.push_back(val);
                i+=2, tmp="";
                if (s[i]==':') break;
            }
        }
        len=v.size();
        for (i=0; i<len; i++){
            for (j=i+1; j<len; j++)
                adj[v[i]].push_back(v[j]),  adj[v[j]].push_back(v[i]);
        }
        v.clear();
    }
}

void init(int n)
{
    mp.clear();
    for (int i=1; i<sz; i++) vis[i]=0, adj[i].clear();
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T, n, m, i=1;
    string s;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        cin.ignore();
        take_in(n, m);
        bfs(mp["Erdos, P."]);

        n=mp.size();
        cout << "Scenario " << i++ << endl;
        while (m--) {
            getline(cin, s);
            n=mp[s];
            cout << s << ' ';
            if (vis[n]) cout << vis[n]-1 << endl;
            else cout << "infinity" << endl;
        }
        init(n);
    }
    return 0;
}
