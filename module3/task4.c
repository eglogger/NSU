#include <stdio.h>

int symbCnt(char *str, char a){

    int cnt = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == a)
            cnt++;

    if (cnt == 3)
        return 1;
}


int main() {

    char str[80];
    gets(str);

    for (int i = 0; str[i] != '\0'; i++) {
    if (symbCnt(str, str[i])) {
        printf("%c", str[i]);
        return 0;
    }
}
    
    return 0;
}