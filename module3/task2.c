#include <stdio.h>
#include <string.h>

int main() {

    char str[80];
    gets(str);

    int cnt = 1;
    int cntmax = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == str[i + 1]) {
            cnt++;
        }
        else if (cntmax < cnt) {
            cntmax = cnt;
            cnt = 1;
        }

    }

    printf("%d", cntmax);

    return 0;
}