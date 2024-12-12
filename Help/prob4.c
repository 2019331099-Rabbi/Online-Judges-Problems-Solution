#include <stdio.h>

int isPowerOfFour(int num) {
    while (num > 1) {
        if (num % 4 != 0) {
            return 0;
        }
        num /= 4;
    }
    return (num == 1);
}

int main() {
    int num;
    scanf("%d", &num);

    if (isPowerOfFour(num)) printf("true\n");
    else printf("false\n");

    return 0;
}
