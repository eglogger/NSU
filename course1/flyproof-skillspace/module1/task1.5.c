#include <stdio.h>

int main() {

    float y, hours, minutes;
    float Pi = 3.14;

    scanf("%f", &y);

    hours = y * 180 / Pi / 30;
    int int_hour = (int) hours;
    minutes = (hours - int_hour) * 60;

    printf("%d hours\n", (int) hours);
    printf("%d minutes\n", (int) minutes);

    return (0);
}
