#include <stdio.h>

int main(){

    int x1, y1, x2, y2, x3, y3, x4, y4;

    scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

    if (x1 < x3)
        printf("%d, ", x1);
    else
        printf("%d, ", x3);

    if (y1 < y3)
        printf("%d\n", y1);
    else
        printf("%d\n", y3);

    if(x2 > x4)
        printf("%d, ", x2);
    else
        printf("%d, ", x4);

    if(y2 > y4)
        printf("%d\n", y2);
    else
        printf("%d\n", y4);

    return 0;
}
