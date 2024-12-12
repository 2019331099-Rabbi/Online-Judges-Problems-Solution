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
    // int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //     int len = gas.size();
    //     int tel = gas[len - 1], lagbe = cost[len - 1];
    //     int starting = len - 1, curr = 0;

    //     while ((starting > curr)) {
    //         while ((tel < lagbe)  && (starting > curr)) {
    //             starting--;
    //             if (starting < 0) starting = len - 1;
    //             tel += gas[starting];
    //             lagbe += cost[starting];
    //         }

    //         if (starting > curr) {
    //             lagbe += cost[curr];
    //             tel += gas[curr];
    //             curr = (curr + 1) % len;
    //         }
    //    }
    //    if (tel < lagbe) return -1;

    //    int cnt = 0;
    //    int pos;

    //    for (int i = 0; i < len; i++) {
    //         if (gas[i]) cnt++, pos = i;
    //    }
    //    if (cnt == 1) return pos;
    //    return starting;
    // }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int len = gas.size();

        for (int i = 0; i < len; i++) totalGas += gas[i], totalCost += cost[i];

        if (totalGas < totalCost) return -1;

        int total = 0, starting = 0;
        for (int i = 0; i < len; i++) {
            total += gas[i] - cost[i];
            if (total < 0) total = 0, starting++;
        }
        return starting;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    vector <int> gas  = {2, 0, 0, 0};
    vector <int> cost = {0, 1, 0, 0};

    cout << soln->canCompleteCircuit(gas, cost) << endl;

    return 0;
}