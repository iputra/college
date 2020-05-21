#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type.h"
#include "function.h"

int main() {
    llist DATA;

    DATA = inis();

    DATA = sisipUrut(DATA,22,"ikhsan");
    DATA = sisipUrut(DATA,24,"putra");
    DATA = sisipUrut(DATA,28,"ari");
    DATA = sisipUrut(DATA,23,"sandi");

    cetak(DATA);
return 0;
}
