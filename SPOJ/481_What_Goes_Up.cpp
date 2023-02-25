#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 10000010
#define inf 1e9 + 9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

using namespace std;
 
int A[1000000], M[1000000], M_id[1000000], P[1000000];
 
void print(int end) {
    if(end < 0) return;
    print(P[end]);
    printf("%d\n", A[end]);
}
 
int main() {
    int L = 0, L_end = 0;
    for(int i = 0;; i++) {
        if(scanf("%d", &A[i]) != 1) break;
 
        int pos = lower_bound(M, M + L, A[i]) - M;
        M[pos] = A[i];
        M_id[pos] = i;
        P[i] = pos > 0? M_id[pos - 1] : -1;
        if(pos == L) {
            L++;
            L_end = i;
        }
    }
    printf("%d\n-\n", L);
    print(L_end);
}