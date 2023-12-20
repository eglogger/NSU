#include <stdio.h>
#include <stdlib.h>

int nod(int a, int b) {                                    // Euclid 's algorithm

    while (a != 0 && b != 0) {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }

    return a + b;
}

int arrNod(int len, int *arr) {

    int result = arr[0];

    for (int i = 0; i < len; i++)
        result = nod(result, arr[i]);

    return result;
}

int main(){

    int len, *arr = malloc(len * sizeof(int));

    scanf_s("%d", &len);

    for (int i = 0; i < len; i++)
        scanf_s("%d", &arr[i]);

    printf("%d", arrNod(len, arr));

    free(arr);

    return 0;
}