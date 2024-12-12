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
    int leastInterval(vector<char>& tasks, int n) {
        vector <int> occ(26, 0);
        for (auto xx: tasks) occ[xx - 'A']++;

        priority_queue <int> pq;
        for (auto xx: occ) if (xx) pq.push(xx);
        
        int result = 0;
        while (!pq.empty()) {
            int time = 0;
            vector <int> tmp;
            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    tmp.push_back(pq.top() - 1);
                    pq.pop();
                    time++;
                }
            }
            for (auto xx: tmp) if (xx) pq.push(xx);
            result += (pq.empty())?time:n+1;
        }
        return result;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();


    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 3;

    cout << soln->leastInterval(tasks, n) << endl;


}

/*
AAAA
BBB
CC
n = 3
A
*/