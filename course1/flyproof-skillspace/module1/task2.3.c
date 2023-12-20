#include <stdio.h>

int main() {

    int a, b, c, d, s1, s2;

    printf("Table`s long part, table`s short part, Cardboard`s long part, cardboard`s short part:");
    scanf_s("%d %d %d %d", &a, &b, &c, &d);

    s1 = a * b;
    s2 = c * d;

    if (a < c || b < d || s1 < s2)
        printf("Wrong input");
    else if ((a / c) >= (a / d))
        printf("Long part");
    else
        printf("Short part");
                                                                                                                                                                                       
    return 0;
}
