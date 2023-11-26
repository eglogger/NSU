#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool DupLetters(char* word) {
    
    for (int i = 0; i < strlen(word); i++) {
        for (int j = i + 1; strlen(word); j++) {
            if (word[i] == word[j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {

    char str[80];
    gets(str);

    char* firstWord = strtok(str, " ");
    char* word = strtok(NULL, " ");
    
    while (word != NULL) {
        if (strcmp(word, firstWord) != 0 && !DupLetters(word)) {
            printf("%s ", word);
        }
        word = strtok(NULL, " ");
    }

    return 0;
}