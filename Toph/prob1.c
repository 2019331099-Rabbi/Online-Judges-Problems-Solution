#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int val;
        scanf("%d", &val);
        if (val >= 10 && val <= 20) cnt++;
    }
    printf("%d in\n%d out\n", cnt, N - cnt);
}
