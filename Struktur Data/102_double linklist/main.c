#include <stdio.h>
#include <linux/string.h>
#include <stdlib.h>
#include "type.h"
#include "function.h"

int main() {
    llist L1;

    L1 = inis();

    L1 = addDepan(L1,2,"Messi");
    L1 = addDepan(L1,7,"Ronaldo");
    L1 = sisipNode(L1,3,8,"Pogba");
    L1 = sisipNode(L1,1,9,"Ibra");

    cetak(L1,0);
    printf("\n");
    L1 = delBelakang(L1);
    cetak(L1,0);
return 0;
}
