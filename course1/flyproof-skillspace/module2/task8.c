#include <stdio.h>

int isPrime(int n) {

    if (n < 2)
        return 0;

    if (n == 2)
        return 1;

    if (n == 3)
        return 1;

    if ((n % 2 != 0) && (n % 3 != 0))
        return 1;
}

int main() {

    int n;

    scanf("%d", &n);

    if (isPrime(n))
        printf("%d is prime", n);
    else
        printf("%d isn`t prime", n);

    return 0;
}