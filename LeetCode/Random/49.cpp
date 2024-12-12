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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector <string>> ump;
        for (auto &word: strs) {
            int occ[26] = {0};
            for (auto &ch: word) occ[ch - 'a']++;

            string s = "";
            for (int i = 0; i < 26; i++) {
                if (occ[i]) {
                    char ch = 'a' + i;
                    s += ch;
                    s += to_string(occ[i]);
                }
            }
            ump[s].push_back(word);
        }
        vector <vector <string>> grp;
        for (auto &pair: ump) grp.push_back(pair.second);
        return grp;
    }
};

int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    Solution *soln = new Solution();

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector <vector <string>> grp = soln->groupAnagrams(strs);

    for (int i = 0; i < grp.size(); i++) {
        for (auto xx: grp[i]) cout << xx << " ";
        cout << endl;
    }
    

}