#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX_LEN (16 + 2)
#define ALPHABET_SIZE 256
#define TEXT_SIZE 1000

// Creating table of symbols with information about shifting.
int *preprocess(char *pattern, int patternLen) {

    int *table = malloc(ALPHABET_SIZE * sizeof(int));

    for (int i = 0; i < ALPHABET_SIZE; i++)
        table[i] = patternLen;

    for (int i = 0; i < strlen(pattern) - 1; i++)
        table[pattern[i]] = patternLen - i - 1;

    return table;
}

// Using Boyer-Moore algorithm.
void BoyerMoore(char *text, char *pattern, int textLen, int patternLen) {

    int i = patternLen - 1;
    int* table = preprocess(pattern, patternLen);

    while (i < textLen) {

        printf("%d ", i + 1);

        int j = 0;

        while ((j < patternLen) &&
              (text[i - j] == pattern[patternLen - 1 - j])) {

            j++;

            if (j != patternLen)
                printf("%d ", i - j + 1);
        }

        i += table[text[i]];
    }

    free(table);
}

int main() {

    char pattern[MAX_LEN];
    char text[TEXT_SIZE];

    int textLen, patternLen;

    fgets(pattern, MAX_LEN, stdin);
    fgets(text, TEXT_SIZE, stdin);

    pattern[strcspn(pattern, "\n")] = 0;
    text[strcspn(text, "\n")] = 0;

    textLen = strlen(text);
    patternLen = strlen(pattern);

    BoyerMoore(text, pattern, textLen, patternLen);

    return 0;
}
