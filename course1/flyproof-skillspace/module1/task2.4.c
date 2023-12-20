#include <stdio.h>

int main() {

    float t, x;

    scanf_s ("%f", &t);

    x = t - t / 10 * 10;

    if ((x >= 0 && x < 3) || (x >= 5 && x < 8))
        printf("Green");
        
    else
        printf("Red");

    return 0;
}
