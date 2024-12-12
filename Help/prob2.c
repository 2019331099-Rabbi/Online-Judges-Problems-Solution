#include <stdio.h>

int removeDuplicates(int arr[], int n) {
    if (n == 0) return 0;

    int uniqueIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[uniqueIndex]) {
            uniqueIndex++;
            arr[uniqueIndex] = arr[i];
        }
    }
    return uniqueIndex + 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int idx = removeDuplicates(arr, n);
    for (int i = 0; i < idx; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
