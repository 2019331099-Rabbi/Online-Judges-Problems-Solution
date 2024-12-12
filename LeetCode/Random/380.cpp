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

class RandomizedSet {
public:
    unordered_map <int, int> myMap;
    vector <int> values;

    RandomizedSet() {}
    
    bool insert(int val) {
        if (myMap.find(val) != myMap.end()) return false;
        myMap[val] = values.size();
        values.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (myMap.find(val) == myMap.end()) return false;

        int lastVal = values.back();
        int idx = myMap[val];
        values[idx] = lastVal;
        myMap[lastVal] = idx;

        myMap.erase(val);
        values.pop_back();
        return true;
    }
    
    int getRandom() {
        int rndidx = rand() % values.size();
        return values[rndidx];
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);    
    RandomizedSet *random = new RandomizedSet();

    cout << random->remove(0) << endl;
    cout << random->remove(0) << endl;
    cout << random->insert(0) << endl;
    cout << random->getRandom() << endl;
    cout << random->remove(0) << endl;
    cout << random->insert(0) << endl;

}