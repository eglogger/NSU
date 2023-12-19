#include<stdio.h>
#include <stdlib.h>
#include <string.h>

// Swap function.
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Checking if input is correct.
int check(char *p) {

    for (int i = 0; i < strlen(p); i++) {

        if ((p[i] < '0') || (p[i] > '9'))
            return 0;

        for (int j = 0; j < strlen(p); j++)
            if ((p[i] == p[j]) && (i != j))
                return 0;
    }

    return 1;
}

// Sorting string in lexicographic order.
void sortString(char *str, int rem, int len) {
    for (int i = rem; i <= len; i++)
        for (int j = i + 1; j <= len; j++)
            if (str[i] > str[j])
                swap(&str[i], &str[j]);
}

// Generating next permutation.
int nextPermutation(char* str, int len) {

    int i = len - 2;
    int j = len - 1;

    while (i >= 0 && str[i] >= str[i + 1])
        i--;
    if (i < 0)
        return 0;

    while (str[i] > str[j])
        j--;

    swap(&str[i], &str[j]);
    sortString(str, i + 1, len - 1);

    return 1;
}

// Generating N permutations after P.
void generatePermutations(char *p, int n) {

    char *current = malloc(strlen(p) - 1);

    strcpy(current, p);

    for (int i = 0; i < n; i++) {
        if (!nextPermutation(current, strlen(p))) {
            return;
        }
        printf("%s\n", current);
    }

    free(current);
}

int main() {

    char p[9];
    int n;

    scanf("%s", p);
    scanf("%d", &n);

    if (!(check(p))) {
        printf("bad input");
        return 0;
    }

    generatePermutations(p, n);

    return 0;
}
