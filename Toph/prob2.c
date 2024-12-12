#include <stdio.h>

int main()
{
    long long int n;
    scanf("%lld", &n);
    if (n <= 3) printf("0\n");
    else printf("%lld\n", n * (n - 3) / 2);
    return 0;
}
