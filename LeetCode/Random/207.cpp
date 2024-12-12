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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> indegree(numCourses, 0), adjMatrix[numCourses];
        for (auto xx: prerequisites) {
            adjMatrix[xx[1]].push_back(xx[0]);
            indegree[xx[0]]++;
        }

        queue <int> q;
        int cnt = 0;

        for (int i = 0; i < numCourses; i++) if (indegree[i] == 0) q.push(i);
        while (!q.empty()) {
            int u = q.front();
            cnt++;
            q.pop();
            for (auto xx: adjMatrix[u]) {
                indegree[xx]--;
                if (indegree[xx] == 0) q.push(xx);
            }
        }
        return cnt == numCourses;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector<vector<int>> prerequisites = {{1, 0}};
    int numCourses = 2;

    cout << soln->canFinish(numCourses, prerequisites);



}