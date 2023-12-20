#include <stdio.h>
#include <string.h>

int main() {

    char str[80];
    int cnt = 0;
    int alphabets[26];

    gets(str);

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') 
            alphabets[str[i] - 'a'] = 1;
        else if (str[i] >= 'a' && str[i] <= 'z')
            alphabets[str[i] - 'a'] = 1;
        
    }

    for (int i = 0; i < 26; i++) {
        if (alphabets[i] == 1)
            cnt++;
    }

    printf("%d", cnt);

    return 0;
}