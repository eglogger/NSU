#include <stdio.h>
#include <string.h>

int main() {
    
    char str[80];
    char* words[80];
    int i = 0, j, n;
    
    gets(str);
    
    char* word = strtok(str, " ");
    
    while (word != NULL) {
        words[i] = word;
        i++;
        word = strtok(NULL, " ");
    }
    
    n = i;
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strlen(words[j]) > strlen(words[j + 1])) {
                char* temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
    
    
    for (i = 0; i < n; i++) {
        printf("%s ", words[i]);
    }
    
    return 0;
}