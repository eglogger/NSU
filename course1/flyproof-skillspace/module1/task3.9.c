#include <stdio.h>
#include <math.h>

int main() {

    float p, p0 = 1.29, z = 1.25 * 0.0001, e = 2.71;

    for(int h = 0; h < 10000; h++) {
        p = p0 * pow(e, -h * z);
        if( p < 1) {
            printf("%d", h);
            return 0;
        }
    }

    return 0;
}
