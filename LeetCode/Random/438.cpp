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
    vector<int> findAnagrams(string text, string pattern)
    {
        int tlen = text.size(), plen = pattern.size();
        if (tlen < plen) return {};

        vector <int> textOcc(26, 0), patternOcc(26, 0);
        vector <int> indexPos;

        for (auto ch: pattern) patternOcc[ch - 'a']++;
        for (int i = 0; i < plen; i++) textOcc[text[i] - 'a']++;

        if (textOcc == patternOcc) indexPos.push_back(0);
        
        int i = pattern.size();
        while (i < tlen) {
            textOcc[text[i] - 'a']++;
            textOcc[text[i - plen] - 'a']--;
            i++;
            if (textOcc == patternOcc) indexPos.push_back(i - plen);
        }
        return indexPos;
    }
};


int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    Solution *soln = new Solution();

    string text = "abcabc", pattern = "abc";

    auto result = soln->findAnagrams(text, pattern);
    for (auto xx: result) cout << xx << ' ';
    cout << endl;


}