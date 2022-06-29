#include <bits/stdc++.h>
#define endl '\n'
#define sz 4
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
int col8[]={1, -1, 0, 0, 1, 1, -1, -1};

int brow8[]={0, 0, 1, -1, -1, 1, 1, -1};///8 adjacent
int bcol8[]={-1, 1, 0, 0, -1, -1, 1, 1};

char grid1[sz][sz], grid2[sz][sz];
int par[sz][sz];
bool vowel[26];
set <string> st, fst;

void words(int xi, int yi, string lword, int sx, int sy)
{
    int bx, by, x, y;
    lword+=grid1[xi][yi];
    if (lword.size()==3) {
        int v_cnt=0;
        v_cnt+=(vowel[lword[0]-'A']+vowel[lword[1]-'A']+vowel[lword[2]-'A']);
        for (int i=0; i<8; i++) {
            x=xi+row8[i];
            y=yi+col8[i];
            if (x<0 || x>=sz || y<0 || y>=sz) continue;
            if (par[xi][yi]==-1) bx=by=-1;
            else bx=xi+brow8[par[xi][yi]], by=yi+bcol8[par[xi][yi]];
            if (x==bx && y==by || x==sx && y==sy) continue;
            if (v_cnt+vowel[grid1[x][y]-'A']==2) {
                st.insert(lword+grid1[x][y]);
            }
        }
        return;
    }
    for (int i=0; i<8; i++) {
        x=xi+row8[i];
        y=yi+col8[i];
        if (x<0 || x>=sz || y<0 || y>=sz) continue;
        if (par[xi][yi]==-1) bx=by=-1;
        else bx=xi+brow8[par[xi][yi]], by=yi+bcol8[par[xi][yi]];
        if (x==bx && y==by || x==sx && y==sy) continue;
        par[x][y]=i;
        words(x, y, lword, sx, sy);
    }
}

void ans(int xi, int yi, string lword, int sx, int sy)
{
    int bx, by, x, y;
    lword+=grid2[xi][yi];
    if (lword.size()==3) {
        int v_cnt=0;
        v_cnt+=(vowel[lword[0]-'A']+vowel[lword[1]-'A']+vowel[lword[2]-'A']);
        for (int i=0; i<8; i++) {
            x=xi+row8[i];
            y=yi+col8[i];
            if (x<0 || x>=sz || y<0 || y>=sz) continue;
            if (par[xi][yi]==-1) bx=by=-1;
            else bx=xi+brow8[par[xi][yi]], by=yi+bcol8[par[xi][yi]];
            if (x==bx && y==by || x==sx && y==sy) continue;
            if (v_cnt+vowel[grid2[x][y]-'A']==2) {
                if (st.erase(lword+grid2[x][y])) fst.insert(lword+grid2[x][y]);
            }
        }
        return;
    }
    for (int i=0; i<8; i++) {
        x=xi+row8[i];
        y=yi+col8[i];
        if (x<0 || x>=sz || y<0 || y>=sz) continue;
        if (par[xi][yi]==-1) bx=by=-1;
        else bx=xi+brow8[par[xi][yi]], by=yi+bcol8[par[xi][yi]];
        if (x==bx && y==by || x==sx && y==sy) continue;
        par[x][y]=i;
        ans(x, y, lword, sx, sy);
    }
}

void ff1()
{
    for (int i=0; i<sz; i++) {
        for (int j=0; j<sz; j++) {
            par[i][j]=-1;
            words(i, j, "", i, j);
        }
    }
    for (int i=0; i<sz; i++) {
        for (int j=0; j<sz; j++) {
            par[i][j]=-1;
            ans(i, j, "", i, j);
        }
    }
    if (fst.size()) for (auto xx: fst) cout << xx << endl;
    else cout << "There are no common words for this pair of boggle boards." << endl;
    st.clear();
    fst.clear();
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    vowel['A'-'A']=true, vowel['E'-'A']=true, vowel['I'-'A']=true, vowel['O'-'A']=true, vowel['U'-'A']=true, vowel['Y'-'A']=true;
    string s;
    int i=0, j, k;
    bool flag=false;

    while (getline(cin, s) && s[0]!='#') {
        if (!s.size()) {
            i=0;
            if (flag) cout << endl;
            flag=true;
            ff1();
            continue;
        }
        j=0;
        for (k=0; k<7; k+=2) grid1[i][j++]=s[k];
        j=0;
        for (k=11; k<18; k+=2) grid2[i][j++]=s[k];
        i++;
    }
    return 0;
}
