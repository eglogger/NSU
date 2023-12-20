#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isPythonName(char* str) {

    for (int i = 0; i < strlen(str); i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return false;
        }
    }

    char* keywords[35] = {"False", "None", "True", "and", "as", "assert", "async",
                          "await", "break", "class", "continue", "def", "del", "elif",
                          "else", "except", "finally", "for", "from", "global", "if",
                          "import", "in", "is", "lambda", "nonlocal", "not", "or",
                          "pass", "raise", "return", "try", "while", "with", "yield"};

    for (int i = 0; i < 35; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return false;
        }
    }

    return true;
}

int main() {

    char str[80];
    gets(str);

    if (isPythonName(str))
        printf("Available name.");
    else
        printf("Unavailable name.");

    return 0;
}