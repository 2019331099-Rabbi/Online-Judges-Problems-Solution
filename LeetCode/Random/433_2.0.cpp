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


class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector <char> chs = {'A', 'T', 'G', 'C'};
        unordered_set <string> ust, vis;

        for (auto &xx: bank) ust.insert(xx);

        queue <pair <string, int>> q;
        q.push({startGene, 0});
        vis.insert(startGene);

        while (!q.empty()) {
            string u = q.front().first;
            int cnt = q.front().second;
            if (u == endGene) return cnt;
            q.pop();

            for (int i = 0; i < 8; i++) {
                char prev = u[i];
                for (auto ch: chs) {
                    u[i] = ch;
                    if (ust.find(u) != ust.end() && vis.find(u) == vis.end()) q.push({u, cnt + 1}), vis.insert(u);
                }
                u[i] = prev;
            }
        }
        return -1;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    string startGene = "AACCGGTT", endGene = "AACCGGTA";
    vector <string> bank = {"AACCGGTA"};

    cout << soln->minMutation(startGene, endGene, bank) << endl;


}