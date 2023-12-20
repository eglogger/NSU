#include <stdio.h>
#include <stdlib.h>

int main() {

    int a, b, c, d, f, e;

    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    if ((abs(e - a) == 2 && abs(f - b)==1) || (abs(e - a) == 1 && abs(f - b) == 2))
        printf("Success\n");
    else {
        printf("Wrong turn\n");
        return 0;
    }


    if ((e == c) || (f == d) || (abs(e - c) == abs(f - d)))
        printf("Dead");
    else
        printf("Alive");

    return 0;
}
