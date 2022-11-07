#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 300
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

struct brick{
    int x1,x2,y1,y2,id;
    brick(int x1, int y1, int x2, int y2, int id):x1(x1),y1(y1),x2(x2),y2(y2),id(id){}
    brick():id(-1){}
};

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int nodes;

    cin >> nodes;
    vector <brick> bricks;
    for (int i = 0; i < nodes; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        bricks.push_back(brick(x1, y1, x2, y2, i));
    }
    sort(bricks.begin(), bricks.end(), [&](auto& x, auto& y){
    if(x.y2 != y.y2) return x.y2 < y.y2;
    else return x.x1 < y.x1;
   });

   for (auto xx: bricks) cout << xx.id << ' ' << xx.x1 << ' ' << xx.y1 << ' ' << xx.x2 << ' ' << xx.y2 << endl;

}