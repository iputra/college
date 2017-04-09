#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "02-function.h"
#include "02-type.h"

int main() {
    llist DATA;

    DATA = inis();
    DATA = addDepan(DATA,23,"test");
    cetak(DATA);
return 0;
}
