#include <stdio.h>
#include <string.h>
#include <math.h>

int val(char c) {          // Returning value of a char.

    if (c >= '0' && c <= '9')
        return (int) c - '0';

    else if (c >= 'A' && c <= 'F')
        return (int) c - 'A' + 10;

    else
        return (int) c - 'a' + 10;
}

char reVal(int num) {          // Returning char of value.

    if (num >= 0 && num <= 9)
        return (char)(num + '0');

    else
        return (char)(num - 10 + 'A');

}

int toDeci(char *str, int base) {          // Converting integer part of a number from given base to decimal.

    int power = strlen(str) - 1;
    int num = 0;

    for (int i = 0; i < strlen(str); i++) {
        num += val(str[i]) * pow(base, power);
        power--;
    }

    return num;
}

double toDeciFrac(char *str, int base) {          // Converting fractional part of a number from given base to decimal.

    int power = -1;
    double num = 0;

    for (int i = 0; i < strlen(str); i++) {
        num += val(str[i]) * pow((double)base, (double)power);
        power--;
    }

    return num;
}

char* fromDeci(char result[], int base, int num) {          // Converting integer part of a number from decimal
                                                           // to given base.
    int i = 0;

    while (num > 0) {
        result[i++] = reVal(num % base);
        num /= base;
    }

    result[i] = '\0';
    strrev(result);

    if (result[0] == '\0')
        result[0] = '0';

    return result;
}

char* fromDeciFrac(char result[], int base, double num) {          // Converting integer part of a number from decimal
    // to given base.
    int i = 0;
    int remainder;

    while (num > 0) {

        num *= base;

        remainder = (int) num;
        num -= remainder;
        result[i] = reVal(remainder);

        i++;
    }

    result[i] = '\0';

    return result;
}

int check(int base1, int base2, char *str) {          // Checking if input is correct.

    int dotCnt = 0;

    if ((base1 < 2 ||base1 > 16) || (base2 < 2 || base2 > 16))
        return 0;

    for (int i = 0; i < strlen(str); i++) {

        if (val(str[i]) >= base1)
            return 0;

        if (str[i] == '.')
            dotCnt++;

        if ((str[i] < '0' && str[i] != '.') || (str[i] > '9' && str[i] < 'A'))
            return 0;
    }

    if (dotCnt > 1)
        return 0;

    if (str[0] == '.' || str[strlen(str) - 1] == '.')
        return 0;

    return 1;
}

void split(char *str, char *str1, char *str2) {          // Splitting string on integer and fractional part of number.

    int dot = 0;
    int m = 0;

    for (int i = 0; i < strlen(str); i++)
        if (str[i] == '.')
            dot = i;

    for (int j = 0; j < dot; j++)
        str1[j] = str[j];

    for (int n = dot + 1; n < strlen(str); n++) {
        str2[m] = str[n];
        m++;
    }
}

int main() {

    int b1, b2;
    int num1;
    double num2;
    char halfStr1[32] = {};
    char halfStr2[32] = {};
    char x[14];

    scanf("%d %d", &b1, &b2);
    scanf("%s", x);

    if (!(check(b1, b2, x))) {
        printf("bad input");
        return 0;
    }

    for (int i = 0; i < strlen(x); i++) {

        if (x[i] == '.') {

            split(x, halfStr1, halfStr2);

            num1 = toDeci(halfStr1, b1);
            num2 = toDeciFrac(halfStr2, b1);

            printf("%s.%s", fromDeci(halfStr1, b2, num1), fromDeciFrac(halfStr2, b2, num2));

            return 0;
        }

    }

    num1 = toDeci(x, b1);

    printf("%s", fromDeci(halfStr1, b2, num1));

    getch();

    return 0;
}
