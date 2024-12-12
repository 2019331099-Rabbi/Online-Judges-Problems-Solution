#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;


int BitsSetTable256[256];
 
// Function to initialise the lookup table 
void initialize() 
{ 
 
    // To initially generate the 
    // table algorithmically 
    BitsSetTable256[0] = 0; 
    for (int i = 0; i < 256; i++)
    { 
        BitsSetTable256[i] = (i & 1) + 
        BitsSetTable256[i / 2]; 
    } 
} 
 
// Function to return the count 
// of set bits in n 
int countSetBits(int n) 
{ 
    return (BitsSetTable256[n & 0xff] + 
            BitsSetTable256[(n >> 8) & 0xff] + 
            BitsSetTable256[(n >> 16) & 0xff] + 
            BitsSetTable256[n >> 24]); 
}



void solve(int T)
{
    string s;
    cin >> s;

    vector <string> v;
    for (auto &ch: s) {
        if (ch == '?') {

        }
    }

    string tmp1 = s, tmp2 = s;
    for (auto &ch: tmp1) if (ch == '?') ch = '0';
    for (auto &ch: tmp2) if (ch == '?') ch = '9';

    size_t non_zero_pos1 = tmp1.find_first_not_of('0');
    size_t non_zero_pos2 = tmp2.find_first_not_of('0');

    if (non_zero_pos1 != string::npos) tmp1 = tmp1.substr(non_zero_pos1);
    else tmp1 = "0";
    if (non_zero_pos2 != string::npos) tmp2 = tmp2.substr(non_zero_pos2);
    else tmp2 = "0";
    

    int n1 = stoi(tmp1);
    int n2 = stoi(tmp2);

    int mx = 0, res;

    for (int i = n1; i <= n2; i++) {
        int cnt = countSetBits(i);
        if (cnt >= mx) res = i, mx = cnt;
    }
    cout << res << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    initialize(); 
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    

    cout << countSetBits(58623) << endl;
    cout << countSetBits(57623) << endl;
    return 0;
}