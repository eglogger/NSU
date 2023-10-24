#include <stdio.h>

int digSqrt(int num) {

    int result;

    if (num < 10)
        result = num;

    else
        result = (num % 10) + digSqrt(num / 10);

    if (result > 10)
        result = digSqrt(result);

    return result;
}

int main() {

    int num;

    scanf_s("%d", &num);

    int sum = digSqrt(num);

    printf("%d", sum);

    return 0;
}