#include <stdio.h>
#include <stdlib.h>

int main() {

    int max = 0;
    int len, *arr = malloc(len * sizeof(int));

    scanf_s("%d", &len);

    for (int i = 0; i < len; i++)
        scanf_s("%d", &arr[i]);

    for (int i = 0; i < len; i++)
        if (arr[i] > max)
            max = arr[i];

    printf("%d", max);

    free(arr);
    return 0;
}