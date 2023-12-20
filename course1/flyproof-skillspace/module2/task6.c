#include <stdio.h>

int digSum(int num) {

    if (num < 10) {
        return num;
    }

    return (num % 10) + digSum(num / 10);
}

int main() {

    int num;

    scanf_s("%d", &num);

    int sum = digSum(num);

    printf("%d", sum);

    return 0;
}