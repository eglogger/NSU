#include <stdio.h>
#include <string.h>

int main() {
    
    char str[80];
    gets(str);
    
    int cnt = 0;
    int cntmax = 0;
    
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            cnt++;
        }
        else if (cntmax < cnt) {
            cntmax = cnt;
            cnt = 0;
        }

    }
    
    printf("%d", cntmax);

    return 0;
}
