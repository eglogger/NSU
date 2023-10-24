#include <stdio.h>
#include <stdlib.h>

int isSymm(int *arr, int i, int j) {

    if (i >= j) {
        return 1;
    }

    if (arr[i] != arr[j]) {
        return 0;
    }

    return isSymm(arr, i + 1, j - 1);
}

int main() {

    int len, *arr = malloc(len * sizeof(int));

    scanf("%d", &len);

    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }

    int i, j;
    
    scanf("%d %d", &i, &j);

    if (isSymm(arr, i, j)) {
        printf("Symmetric");
    } else {
        printf("Asymmetric");
    }

    free(arr);
    return 0;
}