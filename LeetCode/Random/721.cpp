#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 1001
#define inf 1e9 + 9
#define mod 100000000
#define RUN_FAST 
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

vector <int> par;

void makeSet(int len)
{
    for (int i = 0; i < len; i++) par.push_back(i);
}

int findSet(int u)
{
    return (par[u] == u)?u:par[u] = findSet(par[u]);
}

void unionSet(int u, int v)
{
    u = findSet(u);
    v = findSet(v);
    if (u == v) return;
    par[v] = u;
}

vector <vector <string>> accountsMerge(vector<vector<string>>& accounts)
{
    unordered_map <string, int> emails;
    int len = accounts.size();

    makeSet(len);
    for (int i = 0; i < len; i++) {
        for (int j = 1; j < accounts[i].size(); j++) {
            if (emails.find(accounts[i][j]) != emails.end() ) {
                unionSet(emails[accounts[i][j]], i);
            }
            else emails[accounts[i][j]] = i;
        }
    }

    unordered_map <int, set <string>> emailGroups;
    for (auto xx: emails) {
        int u = findSet(xx.second);
        emailGroups[u].insert(xx.first);
    }

    vector <vector <string>> mergedAcc(emailGroups.size());
    int i = 0;
    for (auto xx: emailGroups) {
        mergedAcc[i].push_back(accounts[xx.first][0]);
        for (auto e: xx.second) mergedAcc[i].push_back(e);
        i++;
    }
    return mergedAcc;
}

/**
David0@m.co 0
David4@m.co 0
David3@m.co 0
David5@m.co 1

*/

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // vector<vector<string>> accounts = {
    //     {"David", "David0@m.co", "David4@m.co", "David3@m.co"},
    //     {"David", "David5@m.co"},
    //     {"David", "David1@m.co", "David4@m.co", "David0@m.co"},
    //     {"David", "David0@m.co", "David1@m.co", "David5@m.co"},
    //     {"David", "David4@m.co", "David1@m.co", "David3@m.co"}
    // };

    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}
    };

    auto mergedAcc = accountsMerge(accounts);

    for (auto xx: mergedAcc) {
        for (auto s: xx) cout << s << ' ';
        cout << endl;
    }

    return 0;
}
/*
vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}
    };

*/
