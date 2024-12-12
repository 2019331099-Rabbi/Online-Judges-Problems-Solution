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

auto init = []() -> int {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class DSU{
public:
    unordered_map <int, int> parent;
    DSU(unordered_map <int, int> &ump) {
        for (auto &pr: ump) parent[pr.second] = -1;
    }

    int findSet(int u) {
        return (parent[u] <= -1)?u:parent[u]=findSet(parent[u]);
    }

    void unionSet(int u, int v) {
        u = findSet(u);
        v = findSet(v);
        if (u == v) return;
        parent[u] += parent[v];
        parent[v] = u;
    }
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        unordered_map <int, int> ump;

        for (int i = 0; i < len; i++) ump[nums[i]] = i;
        DSU *dsu = new DSU(ump);

        for (auto &pr: ump) {
            int val = pr.first;
            int idx = pr.second;

            if (ump.find(val - 1) != ump.end()) dsu->unionSet(ump[val - 1], idx);
            if (ump.find(val + 1) != ump.end()) dsu->unionSet(idx, ump[val + 1]);
        }
        int mx = 0;
        for (auto &pr: ump) {
            int x = dsu->findSet(pr.second);
            mx = max(mx, abs(dsu->parent[x]));
        }
        return mx;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution *soln = new Solution();

    vector <int> nums = {0,3,7,2,5,8,4,6,0,1};
    cout << soln->longestConsecutive(nums) << endl;
    return 0;


}