#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int *twosum(int arr[], int n, int target)
{
    
    int farr[n][2];
    for (int i = 0; i < n; i++) farr[i][0] = arr[i], farr[i][1] = i;
    qsort(farr, n, sizeof(farr[0]), compare);

    int i = 0, j = n - 1;
    int* result = (int*)malloc(2 * sizeof(int));
    while (i < j) {
        int tmp = farr[i][0] + farr[j][0];
        if (tmp == target) {
            result[0] = farr[i][1], result[1] = farr[j][1];
            break;
        }
        else if (tmp>target) j--;
        else i++;
    }
    return result;
}

int main()
{
    int n, target;
    scanf("%d %d", &n, &target);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int *result = twosum(arr, n, target);
    printf("%d %d\n", result[0], result[1]);

    return 0;
}