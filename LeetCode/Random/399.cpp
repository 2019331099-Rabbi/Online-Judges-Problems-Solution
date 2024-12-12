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
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map <string, vector <pair <string, double>>> adjMatrix;

        for (int i = 0; i < values.size(); i++) {
            string u = equations[i][0], v = equations[i][1];
            adjMatrix[u].push_back({v, values[i]});
            adjMatrix[v].push_back({u, 1.0 / values[i]});
        }

        vector <double> divRes;

        for (auto query: queries) {
            string dst = query[1];
            double tmp = -1.0;

            if (adjMatrix.find(dst) != adjMatrix.end()) {
                unordered_set <string> vis;
                queue <pair <string, double>> q;

                q.push({query[0], 1.0});
                vis.insert(query[0]);
                while (!q.empty()) {
                    string u = q.front().first;
                    double res = q.front().second;
                    if (adjMatrix.find(u) == adjMatrix.end()) break;
                    if (u == dst) {
                        tmp = res;
                        break;
                    }
                    q.pop();

                    auto neighbors = adjMatrix[u];
                    for (auto neighbor: neighbors) {
                        if (vis.find(neighbor.first) != vis.end()) continue;
                        q.push({neighbor.first, res * neighbor.second});
                        vis.insert(neighbor.first);
                    }
                }
            }
            divRes.push_back(tmp);
        }
        return divRes;
    }
};

/*
a / b = 2.0
b / c = 3.0

for (auto entry: adjMatrix) {
                string key = entry.first;
                vector<pair<string, double>> neighbors = entry.second;
                cout << key << ": ";
                for (auto neighbor: neighbors) cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
                cout << endl;
            }
            cout << "----------------" << endl;
*/

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector<vector<string>> equations = {{"a", "b"}};
    vector <double> values = {3.0};
    vector<vector<string>> queries = {{"c", "b"}, {"c", "c"}};

    vector <double> divRes = soln->calcEquation(equations, values, queries);
    for (auto xx: divRes) cout << xx << endl;

    return 0;
}