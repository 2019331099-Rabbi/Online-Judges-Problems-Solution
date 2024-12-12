#include <stdio.h>

int isPalindrome(int x) {
    int original = x;
    int reversed = 0;

    while (x > 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }
    return (original == reversed);
}

int main() {
    int x;

    scanf("%d", &x);

    // Check if the entered number is a palindrome
    if (isPalindrome(x)) printf("True");
    else printf("False");

    return 0;
}
