#include <stdio.h>
#include <string.h>

int main() {

    char str[80];
    gets(str);

    int shortest = 10000;
    char *words;

    words = strtok(str, " ");

    while (words != NULL) {
        if (shortest > strlen(words)) {
            shortest = strlen(words);
        }
        words = strtok (NULL, " ");
    }

    printf("%d", shortest);

    return 0;
}