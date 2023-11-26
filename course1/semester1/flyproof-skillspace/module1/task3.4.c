#include <stdio.h>
#include <math.h>

int main(){

    double n = sqrt(50);

    for(int i = 49; i > 0; i--)
        n = sqrt(i + n);

    printf("%f", n);

    return 0;
}