#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX_LEN (16 + 2)

// Creating table of symbols with information about shifting.
int *preprocess(char *pattern, int startIndex, int endIndex) {

    int *table = malloc((endIndex - startIndex + 1) * sizeof(int));

    for (int i = 0; i < endIndex - startIndex + 1; i++)
        table[i] = strlen(pattern);

    for (int i = 0; i < strlen(pattern) - 1; i++)
        table[pattern[i] - startIndex] = strlen(pattern) - i - 1;

    return table;
}

// Using Boyer-Moore algorithm.
void BoyerMoore(char* text, char* pattern) {

    int i = strlen(pattern) - 1;
    int start = ' ';
    int end = '~';
    int* table = preprocess(pattern, start, end);

    while (i < strlen(text)) {

        printf("%d ", i + 1);

        int j = 0;

        while (j < strlen(pattern) && text[i - j] == pattern[strlen(pattern) - 1 - j]) {

            j++;

            if (j != strlen(pattern))
                printf("%d ", i - j + 1);
        }

        i += table[text[i] - start];
    }

    free(table);
}

int main() {

    char pattern[MAX_LEN];
    char text[1000];

    fgets(pattern, MAX_LEN, stdin);
    fgets(text, 1000, stdin);

    pattern[strcspn(pattern, "\n")] = 0;
    text[strcspn(text, "\n")] = 0;

    BoyerMoore(text, pattern);

    return 0;
}
