#include <stdio.h>
#include <stdlib.h>
#include <linux/string.h>
#include "02-type.h"
#include "02-function.h"

int main() {
    llist DATA;

    DATA = inis();
    DATA = sisipUrut(DATA,23,"lin");
    DATA = sisipUrut(DATA,32,"ken");
    DATA = sisipUrut(DATA,2,"han");
    cetak(DATA);
    printf("\n");
    DATA = delKe(DATA,2);
    cetak(DATA);
    printf("\n");
return 0;
}
