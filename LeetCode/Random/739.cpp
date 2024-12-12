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
    vector <int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        stack <int> stk;
        vector <int> results(len);

        for (int i = len - 1; i >= 0; i--) {
            while (!stk.empty() && (temperatures[stk.top()] <= temperatures[i])) stk.pop();
            if (stk.empty()) results[i] = 0;
            else results[i] = stk.top() - i;
            stk.push(i);
        }
        return results;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <int> temperatures = {89,62,70,58,47,47,46,76,100,70};
    auto results = soln->dailyTemperatures(temperatures);
    for (auto xx: results) cout << xx << ' ';
    cout << endl;



}