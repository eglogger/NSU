#include <stdio.h>

int main() {

    int a3, a2, a1, b2, b1, ab3, ab2, ab1;

    scanf("%d %d %d", &a3, &a2, &a1);
    scanf("%d %d", &b2, &b1);

    ab1 = (a1 + b1) % 10;
    ab2 = (a2 + b2 + (a1 + b1) / 10) % 10;
    ab3 = a3 + (a2 + b2 + (a1 + b1) / 10) / 10;

    printf("%d %d %d", ab3, ab2, ab1);

    return 0;
}
