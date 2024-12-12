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

class TimeMap {
private:
    unordered_map <string, vector <pair <string, int>>> data;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        int left = 0, right = data[key].size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (data[key][mid].second <= timestamp) left = mid + 1;
            else right = mid - 1;
        }
        if (right >= 0) return data[key][right].first;
        else return "";
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    TimeMap* timeMap = new TimeMap();
    timeMap->set("foo", "bar", 1);
    cout << timeMap->get("foo", 1) << endl;
    cout << timeMap->get("foo", 3) << endl;
    timeMap->set("foo", "bar2", 4);
    cout << timeMap->get("foo", 4) << endl;
    cout << timeMap->get("foo", 5) << endl;

    return 0;
}
/*
0 1 2 3 4 5 6 7 8 9
0 1 1 1 2 2 2 2 3 4

timestamp = -4
0 9 => 4
0 3 => 1
0 0 => 0
0 -1

timestamp = 5
0 9 => 4
5 9 => 6
7 9 => 8
9 9 => 9
10 9

timestamp = 1
0 9 => 4
0 3 => 1
2 3 => 2
3 3 => 3
4 3

timestamp = 2
0 9 => 4
5 9 => 6
7 9 => 8
7 8 => 7
8 8 => 8
8 7
*/