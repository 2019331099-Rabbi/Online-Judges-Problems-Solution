#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 22
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

list <int> pq;
vector <int> ridenSeats[sz];
int occu[sz];

void init()
{
    pq.clear();
    for (int i = 0; i < sz; i++) ridenSeats[i].clear(), occu[i] = 0;
}

bool isRidden(int bottom, int p)
{
    for (auto xx: ridenSeats[p]) if (bottom == xx) return true;
    return false;
}

void solve(int T)
{
    int person, seat;
    cin >> person >> seat;

    for (int i = 1; i <= person; i++) pq.push_back(i);
    int cnt = 0, lim = person * seat, bottom = 1, totTime = 0;

    // cout << "Bot " << bottom << endl;
    // cout << "que: ";
    // for (auto xx: pq) cout << xx << ' ';
    // cout << endl;
    // for (int i = 1; i <= seat; i++) cout << i << ' ' << occu[i] << endl;
    // cout << endl;

    while(cnt < lim) {
        if (occu[bottom]) pq.push_back(occu[bottom]), occu[bottom] = 0, cnt++;

        for (auto xx: pq) {
            if (isRidden(bottom, xx)) continue;
            occu[bottom] = xx;
            pq.remove(xx);
            ridenSeats[xx].push_back(bottom);
            break;
        }
        bottom = (bottom + 1) % (seat + 1);
        if (!bottom) bottom++;
        totTime += 5;

        // cout << "Bot " << bottom << endl;
        // cout << "que: ";
        // for (auto xx: pq) cout << xx << ' ';
        // cout << endl;
        // for (int i = 1; i <= seat; i++) cout << i << ' ' << occu[i] << endl;
        // cout << endl;
    }
    // for (int i = 1; i <= person; i++) {
    //     cout << i << ": ";
    //     for (auto xx: ridenSeats[i]) cout << xx << ' ';
    //     cout << endl;
    // }
    cout << "Case " << T << ": " << totTime << endl;
    init();
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}