#include <stdio.h>
#include <stdlib.h>

int main() {

    int len;
    int *arr = malloc(len * sizeof(int));

    scanf_s("%d", &len);

    for (int i = 0; i < len; i++)
        scanf("%d", &arr[i]);

    int maxGrpLen = 0;
    int GrpLen = 0;

    for (int i = 0; i < len; i++)
        if (arr[i] % 2 != 0) {
            GrpLen++;
        }
    
        else {
            if (GrpLen > maxGrpLen) {
                maxGrpLen = GrpLen;
            }
            GrpLen = 0;
        }

    if (GrpLen > maxGrpLen)
        maxGrpLen = GrpLen;

    printf("%d", maxGrpLen);

    free(arr);
    return 0;
}