#include <stdio.h>

int isFibonacci(long long num, long long a, long long b)
{
    if (num == a || num == b) return 1;
    if (num < a + b) return 0;
    return isFibonacci(num, b, a + b);
}

int main() {
    long long int num;
    scanf("%lld", &num);

    if (isFibonacci(num, 0, 1)) printf("yes\n");
    else printf("no\n");

    return 0;
}
