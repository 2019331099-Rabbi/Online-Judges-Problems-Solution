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
    bool isHappy(int n) {
        unordered_set <int> ust;
        ust.insert(n);
        while (n != 1) {
            int sum = 0;
            while (n) {
                int tmp = n % 10;
                sum += tmp*tmp;
                n /= 10;
            }
            n = sum;
            if (ust.find(n) != ust.end()) return false;
            ust.insert(n);
        }
        return true;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution *soln = new Solution();

    int n = 2;
    cout << soln->isHappy(n) << endl;

}