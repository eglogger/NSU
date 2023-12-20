#include <stdio.h>

int main() {

    float a, a2, a4, a8, a16, a24, a28;

    scanf("%f", &a);

    a2 = a * a;
    a4 = a2 * a2;
    a8 = a4 * a4;
    a16 = a8 * a8;
    a24 = a16 * a8;
    a28 = a24 * a4;

    printf("%f", a28);

    return 0;
}
