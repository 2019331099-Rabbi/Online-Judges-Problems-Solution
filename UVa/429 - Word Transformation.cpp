#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 700
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

//int row[]={0, 0, -1, 1};///4 adjacent(Up, down, left, right)
//int col[]={1, -1, 0, 0};

//int row[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int col[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

map <string, int> mp;

int bfs(int src, int dest, int nodes, vector <int> adj[])
{
    int dis[nodes]={0}, len, tmp, i;
    queue <int> q;
    q.push(src);
    dis[src]=1;

    while (!q.empty()) {
        nodes=q.front();
        q.pop();
        len=adj[nodes].size();
        for (i=0; i<len; i++) {
            tmp=adj[nodes][i];
            if (dis[tmp]) continue;
            dis[tmp]=dis[nodes]+1;
            q.push(tmp);
        }
        if (dis[dest]) return dis[dest]-1;
    }
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    bool flag=false;
    int T, nodes, tmp1, tmp2, len, i, cnt;
    string s1, s2;
    cin >> T;
    while (T--) {
        if (flag) cout << endl;
        flag=true;
        nodes=0;
        while (cin >> s1) {
            if (s1[0]=='*') break;
            mp[s1]=nodes++;
        }
        vector <int> adj[nodes];
        for (auto it1=mp.begin(); it1!=mp.end(); ) {
            s1=it1->first, tmp1=it1->second;
            len=s1.size();
            it1++;
            for (auto it2=it1; it2!=mp.end(); it2++) {
                s2=it2->first, tmp2=it2->second;
                if (len!=s2.size()) continue;
                cnt=0;
                for (i=0; i<len && cnt<2; i++) {
                    if (s1[i]==s2[i]) continue;
                    cnt++;
                }
                if (cnt==1) {
                    adj[tmp1].push_back(tmp2);
                    adj[tmp2].push_back(tmp1);
                }
            }
        }
        cin.ignore();
        while (getline(cin, s1)) {
            if (!s1.size()) break;
            len=s1.size()/2;
            s2=s1.substr(0, len), s1=s1.substr(len+1, len);
            cout << s2 << ' ' << s1 << ' ';
            tmp1=mp[s2], tmp2=mp[s1];
            tmp1=(tmp1==tmp2)?0:bfs(tmp1, tmp2, nodes, adj);
            cout << tmp1 << endl;
        }
        mp.clear();
    }
    return 0;
}
