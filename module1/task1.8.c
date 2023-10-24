// Известно, сколько в доме этажей и сколько квартир на каждой площадке в подъезде (значения вводятся с клавиатуры).
// По заданному номеру квартиры, определить в каком подъезде и на каком этаже находится квартира.

#include <stdio.h>
#include <math.h>

int main() {

    float floors, flatspersite, flatn, entn, floorn, flatsperent;

    scanf_s("%f %f", &floors, &flatspersite);
    scanf_s("%f", &flatn);

    flatsperent = floors * flatspersite;
    entn = ceil(flatn / flatsperent);
    floorn = ceil((flatn - ((entn - 1) * flatspersite * floors)) / flatspersite);

    printf("%d\n", (int)entn);
    printf("%d", (int)floorn);

    return(0);
}
