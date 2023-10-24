#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isLucky(char* str) {

    if (strlen(str) % 2 != 0)
        return false;

    int halfLen = strlen(str) / 2;
    int frstHalfSum = 0;
    int scndHalfSum = 0;

    for (int i = 0; i < halfLen; i++) {
        frstHalfSum += (int) str[i];
    }

    for (int i = halfLen; i < strlen(str); i++) {
        scndHalfSum += (int) str[i];
    }

    if (frstHalfSum == scndHalfSum)
        return true;

    return false;

}

int main() {

    char str[80];
    int cnt = 1;

    while (1) {

        scanf("%s", str);

        if (isLucky(str)) {
            printf("Lucky ticket number: %d", cnt);
            return 0;
        }

        cnt++;
    }
}