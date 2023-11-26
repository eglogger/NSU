#include <stdio.h>
#include <string.h>

int main(){

    char number[80];
    int bulls = 0;
    int cows = 0;

    gets(number);

    for (int i = 0; i < 25; i++)
        printf("\n");

    for (int k = 0; k < 10; k++) {

        char guess[80];
        scanf("%s", guess);

        if (strcmp(guess, number) == 0) {
            printf("Bulls: %d, Cows: 0\n", strlen(number));
            printf("You won!");
            return 0;
        }

        for (int i = 0; i < strlen(number); i++) {
            if (guess[i] == number[i]) {
                bulls++;
            }
        }

        for (int i = 0; i < strlen(number); i++) {
            for (int j = 0; j < strlen(number); j++) {
                if ((guess[i] == number[j]) && (i != j))
                    cows++;
            }
        }

        printf("Bulls: %d, Cows: %d\n", bulls, cows);
        
        bulls = 0;
        cows = 0;
        
        }

    printf("You lost!");

    return 0;

    }