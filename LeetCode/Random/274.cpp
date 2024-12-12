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
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        vector <int> occ(len + 1, 0);
        for (auto xx: citations) {
            if (xx > len) xx = len;
            occ[xx]++;
        }
        citations.clear();

        for (int i = 0; i <= len; i++)
            while (occ[i]--) citations.push_back(i);

        for (int i = 0; i < len; i++) if (len - i <= citations[i]) return len - i;
        return 0;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <int> nums = {3,0,6,1,5};
    cout << soln->hIndex(nums) << endl;
}