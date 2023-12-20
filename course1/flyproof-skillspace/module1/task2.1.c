#include <windows.h>
#include <stdio.h>

int main() {

    SetConsoleOutputCP(CP_UTF8);

    int k;

    scanf_s("%d", &k);

    if (k % 10 == 1)
        printf("%d гриб");
    else if (k % 10 >= 2 && k % 10 <= 4)
        printf("%d гриба", k);
    else
        printf("%d грибов", k);

    return 0;
}
