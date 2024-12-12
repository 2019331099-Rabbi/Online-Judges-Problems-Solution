#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row[] = {0, 0, -1, 1, -1, 1, -1, 1};
// int col[] = {1, -1, 0, 0, -1, 1, 1, -1};

void addNextWords(string word, unordered_set <string> &wordSet, queue <string> &pq)
{
    wordSet.erase(word);
    for (int i = 0; i < word.size(); i++) {
        char ch = word[i];
        for (int j = 0; j < 26; j++) {
            word[i] = 'a' + j;
            if (wordSet.find(word) != wordSet.end()) {
                pq.push(word);
                wordSet.erase(word);
            }
        }
        word[i] = ch;
    }
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
    unordered_set <string> wordSet(wordList.begin(), wordList.end());
    if (wordSet.find(endWord) == wordSet.end()) return 0;

    queue <string> pq;
    addNextWords(beginWord, wordSet, pq);
    int distance = 2;
    while (!pq.empty()) {
        int n = pq.size();
        while (n--) {
            string word = pq.front();
            pq.pop();
            if (word == endWord) return distance;
            addNextWords(word, wordSet, pq);
        }
        distance++;
    }
    return 0;
}

int main()
{
    RUN_FAST;
    cin.tie(nullptr);

    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout << ladderLength(beginWord, endWord, wordList) << endl;

    return 0;

}