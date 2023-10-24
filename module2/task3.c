#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rFill(int *arr, int len) {

    for (int i; i < len; i++)
        arr[i] = rand();

    return 0;
}

int main() {

    srand(time(NULL));

    int len, *arr = malloc(len * sizeof(int));

    scanf_s("%d", &len);

    rFill(arr, len);

    for (int i = 0; i < len; i++)

        printf("%d ", arr[i]);

    free(arr);
    return 0;
}
