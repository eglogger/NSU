// Даны два целых числа a и b. Если a делится на b или b делится на a, то вывести 1, иначе — любое другое число. Условные операторы и операторы цикла не использовать.

#include <stdio.h>

int main() {

    int a, b, t1, t2;

    scanf("%d %d", &a, &b);

    t1 = a % b;
    t2 = b % a;

    printf("%d", t1 + t2 + 1);

    return(0);
}