#include <stdio.h>
#include <stdlib.h>

int* NumSum(int* num1, int* num2, int len1, int len2, int *len3) {

    *len3 = (len1 > len2 ? len1 : len2 + 1);

    int *sum = malloc(*len3 * sizeof(int));

    for (int i = 0; i < *len3; i++) {

        int temp;

        if (i < len1)
            temp += num1[i];
        if (i < len2)
            temp += num2[i];

        sum[i] = temp % 10;
        temp = temp / 10;
    }

    if (sum[*len3 - 1] == 0)
        (*len3)--;

    return sum;
}

int main() {

    int len1, len2, len3;

    scanf("%d", &len1);
    scanf("%d", &len2);


    int* num1 = (int*)malloc(len1 * sizeof(int));
    int* num2 = (int*)malloc(len2 * sizeof(int));

    for (int i = len1 - 1; i >= 0; --i) {
        scanf("%d", &num1[i]);
    }

    for (int i = len2 - 1; i >= 0; --i) {
        scanf("%d", &num2[i]);
    }

    int* sum = NumSum(num1, num2, len1, len2, &len3);

    for (int i = len3 - 1; i >= 0; --i) {
        printf("%d", sum[i]);
    }
    printf("\n");

    free(num1);
    free(num2);
    free(sum);

    return 0;
}