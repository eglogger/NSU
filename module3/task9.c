#include <stdio.h>
#include <string.h>

int main() {

    char str[80];
    char* words[80];
    int i = 0, n, j;

    gets(str);

    char* word = strtok(str, " ");

    while (word != NULL) {
        words[i] = word;
        i++;
        word = strtok(NULL, " ");
    }

    n = i;

    for( i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++){
            if (strcmp(words[i], words[j]) == 0)
                printf("%s ", words[i]);
        }
    }

    return 0;
}