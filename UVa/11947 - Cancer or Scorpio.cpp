#include <bits/stdc++.h>
#define endl '\n'
#define sz 280
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <vector <string>> zods(13, vector <string>(32));
int day[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void preset()
{
    int i;
    string s="aquarius";
    for (i=21; i<32; i++) zods[1][i]=s;
    for (i=1; i<20; i++) zods[2][i]=s;
    s="pisces";
    for (i=20; i<32; i++) zods[2][i]=s;
    for (i=1; i<21; i++) zods[3][i]=s;
    s="aries";
    for (i=21; i<32; i++) zods[3][i]=s;
    for (i=1; i<21; i++) zods[4][i]=s;
    s="taurus";
    for (i=21; i<32; i++) zods[4][i]=s;
    for (i=1; i<22; i++) zods[5][i]=s;
    s="gemini";
    for (i=22; i<32; i++) zods[5][i]=s;
    for (i=1; i<22; i++) zods[6][i]=s;
    s="cancer";
    for (i=22; i<32; i++) zods[6][i]=s;
    for (i=1; i<23; i++) zods[7][i]=s;
    s="leo";
    for (i=23; i<32; i++) zods[7][i]=s;
    for (i=1; i<22; i++) zods[8][i]=s;
    s="virgo";
    for (i=22; i<32; i++) zods[8][i]=s;
    for (i=1; i<24; i++) zods[9][i]=s;
    s="libra";
    for (i=24; i<32; i++) zods[9][i]=s;
    for (i=1; i<24; i++) zods[10][i]=s;
    s="scorpio";
    for (i=24; i<32; i++) zods[10][i]=s;
    for (i=1; i<23; i++) zods[11][i]=s;
    s="sagittarius";
    for (i=23; i<32; i++) zods[11][i]=s;
    for (i=1; i<23; i++) zods[12][i]=s;
    s="capricorn";
    for (i=23; i<32; i++) zods[12][i]=s;
    for (i=1; i<21; i++) zods[1][i]=s;
}

bool isleap(int y)
{
    return ((!(y%4) && y%100) || !(y%400));
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    preset();
    int T, t, d, m, y, i;
    string s, tmps;
    cin >> T;
    for (t=1; t<=T; t++) {
        cin >> s;
        tmps="";
        tmps+=s[0], tmps+=s[1];
        m=stoi(tmps);

        tmps="";
        tmps+=s[2], tmps+=s[3];
        d=stoi(tmps);

        tmps="";
        tmps+=s[4], tmps+=s[5], tmps+=s[6], tmps+=s[7];
        y=stoi(tmps);
        day[2]=28;
        if (isleap(y)) day[2]=29;
        for (i=0; i<sz; i++) {
            d++;
            if (d>day[m]) {
                d=1, m++;
                if (m>12) {
                    m=1, y++;
                    day[2]=isleap(y)?29:28;
                }
            }
        }
        cout << t << ' ';
        if (m<10) cout << '0';
        cout << m << '/';
        if (d<10) cout << '0';
        cout << d << '/';
        cout << y << ' ' << zods[m][d] << endl;
    }
    return 0;
}
