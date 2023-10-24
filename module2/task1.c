#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sqr(int num) {
    if(sqrt(num) - (int) sqrt(num) == 0)
        return 1;

    return 0;
}

int main() {

    int len, cnt = 0;
    int *arr = malloc(len * sizeof(int));

    scanf_s("%d", &len);

    for (int i = 0; i < len; i++)
        scanf_s("%d", &arr[i]);

    for (int i = 0; i < len; i++)
        if (sqr(arr[i]))
            cnt++;

    printf("%d", cnt);

    free(arr);
    return 0;
}
