#include <stdio.h>
#include <stdlib.h>

int rmvDups(int *arr, int len, int *newLen) {

    for (int i = 0; i < len; i ++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < len - 1; k++) {
                    arr[k] = arr [k + 1];
                }
                len--;
                j--;
            }
        }
    }

    *newLen = len;

    return *arr;
}

int main() {

    int len, *arr = malloc(len * sizeof(int));

    scanf_s("%d", &len);

    for (int i = 0; i < len; i++)
        scanf_s("%d", &arr[i]);

    int newLen;

    *arr = rmvDups(arr, len, &newLen);

    for (int i = 0; i < newLen; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}