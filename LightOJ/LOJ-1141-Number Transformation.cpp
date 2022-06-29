#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 1002
#define mod 10000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <int> primes={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
vector <int> adj[sz];

void init()
{
    int i, j, p, tmp, lim;
    bool flag;
    for (i=1; i<1001; i++) {
        tmp=i;
        lim=sqrt(tmp+1)+1;
        for (j=0; primes[j]<lim; j++) {
            p=primes[j];
            flag=false;
            while (tmp%p==0) tmp/=p, flag=true;
            if (flag) adj[i].push_back(i+p);
            if (tmp==1) break;
        }
        if (tmp>1 && tmp!=i) adj[i].push_back(i+tmp);
    }
}

int bfs(int from, int to)
{
    int i, x, tmp, vis[sz+10]={0};
    queue <int> q;
    q.push(from), vis[from]=1;

    while (!q.empty()) {
        x=q.front();
        q.pop();
        for (i=0; i<adj[x].size(); i++) {
            tmp=adj[x][i];
            if (vis[tmp] || tmp>to) continue;
            vis[tmp]=vis[x]+1;
            q.push(tmp);
        }
        if (vis[to]) return vis[to]-1;
    }
    return -1;
}

int main()
{
    RUN_FAST; //cin.tie(nullptr);
    init();
    int T, from, to, i=1;
    cin >> T;
    while (T--) {
        cin >> from >> to;
        cout << "Case " << i++ << ": " << bfs(from, to) << endl;
    }
    return 0;
}
