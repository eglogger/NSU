#include <stdio.h>
#include <string.h>

int main() {

    char str[80];
    char* words[80];
    int i = 0, n;

    gets(str);
    
    char* word = strtok(str, " ");

    while (word != NULL) {
        words[i] = word;
        i++;
        word = strtok(NULL, " ");
    }

    n = i;

    for(i = 1; i < n; i++) {
        if (words[i - 1][strlen(words[i - 1]) - 1] != words[i][0]){
            if (i % 2 == 0) {
                printf("Petya lost");
                return 0;
            }

            else {
                printf("Vasya lost");
                return 0;
            }
        }
    }

    if (n % 2 == 0)
        printf("Vasya won");
    else
        printf("Petya won");

    return 0;
}