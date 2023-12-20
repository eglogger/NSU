#include <stdio.h>
#include <string.h>

int main() {

    char str[80];
    gets(str);

    printf("%s", strrev(str));

    return 0;
}