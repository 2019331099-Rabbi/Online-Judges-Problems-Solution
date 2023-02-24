#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 300
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

struct brick{
    int x1, x2, y1, y2, id;
    brick(int x1, int y1, int x2, int y2, int id):x1(x1),y1(y1),x2(x2),y2(y2),id(id){}
};


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int nodes;

    cin >> nodes;
    vector <brick> bricks;
    map <int, vector <brick>> mp;
    for (int i = 0; i < nodes; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        bricks.push_back(brick(x1, y1, x2, y2, i));
        mp[y2].push_back(brick(x1, y1, x2, y2, i));
    }

    sort(bricks.begin(), bricks.end(), [&](auto &point1, auto &point2){
        if(point1.y2 != point2.y2) return point1.y2 < point2.y2;
        else return point1.x1 < point2.x1;
    });

    for(auto [i, v]: mp) {
        sort(v.begin(), v.end(), [&](auto &point1, auto &point2) {
        return point1.x1 < point2.x1;
        });
    };


    // for (auto xx: bricks) cout << xx.id << ' ' << xx.x1 << ' ' << xx.y1 << ' ' << xx.x2 << ' ' << xx.y2 << endl;
    // for(auto& [i, v] : mp){
    //     cout << i << endl;
    //     for (auto xx: v) cout << xx.id << ' ' << xx.x1 << ' ' << xx.y1 << ' ' << xx.x2 << ' ' << xx.y2 << endl;
        
    // }
}