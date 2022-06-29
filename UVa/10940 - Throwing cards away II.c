#include <stdio.h>
#include <math.h>

int main()
{
    int n, tmp;
    double l2=log10(2);
    while (scanf("%d", &n)) {
        if (!n) break;
        tmp=ceil(log10(n)/l2);
        tmp=pow(2, tmp);
        printf("%d\n", n+n-tmp);
    }
    return 0;
}
