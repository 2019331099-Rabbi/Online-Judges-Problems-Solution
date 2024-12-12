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
    string addBinary(string a, string b) {
        int pos1 = a.size(), pos2 = b.size(), cnt = max(pos1, pos2);

        string sum = "";
        int carry = 0;

        while (cnt--) {
            pos1--, pos2--;
            int tmp = carry;
            if (pos1 >= 0) tmp += a[pos1]-'0';
            if (pos2 >= 0) tmp += b[pos2]-'0';

            sum += (tmp % 2) + '0';
            carry = tmp / 2;
        }
        if (carry) sum += '1';
        reverse(sum.begin(), sum.end());
        return sum;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    string a = "1111", b = "1111";
    cout << soln->addBinary(a, b) << endl;

    return 0;
}