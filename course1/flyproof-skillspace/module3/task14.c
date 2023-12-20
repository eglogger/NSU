#include <stdio.h>
#include <string.h>

int main(){

    char hint[80], word[80], riddle[80];

    gets(hint);
    gets(word);

    for (int i = 0; i < strlen(word); i++) {
        riddle[i] = '*';
        riddle[i+1] = '\0';
    }

    for (int i = 0; i < 25; i++)
        printf("\n");

    printf("%s\n", hint);
    printf("%s\n", riddle);

    for (int k = 0; k < 10; k++) {

        int cnt = 0;
        char choise[1];
        char answer[80];

        printf("(0 - guess letter, 1 - guess word):");
        scanf("%s", choise);

        if (choise[0] == '0') {

            scanf("%s", answer);

            for (int i = 0; i < strlen(word); i++)

                if (word[i] == answer[0])
                    riddle[i] = word[i];

            printf("%s\n", riddle);

            for (int i = 0; i < strlen(word); i++)
                if (riddle[i] == '*')
                    cnt++;

            if (cnt == 0) {
                printf("You won!");
                return 0;
            }
        }

        else if (choise[0] == '1'){

            scanf("%s", answer);

            if (strcmp(answer, word) == 0) {

                printf("You won!");
                return 0;
            }
        }
        else
            printf("Wrong choice, try again.\n");
    }

    printf("You lost!");

    return 0;

}