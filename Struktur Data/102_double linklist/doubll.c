#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipe.h"
#include "Fung.h"

int main ()
{
    linklist L1,L2,L3;

    L1 = inis();
    L2 = inis();


    L1 = sisipUrut(L1,15,"ikhsan");
    L1 = sisipUrut(L1,18,"putra");
    L1 = sisipUrut(L1,23,"arisandi");
    L2 = sisipUrut(L2,20,"diani");
    L2 = sisipUrut(L2,1,"diani");
    cetak(L1,0);
    printf("\n");
    printf("\n");
    L2 = sisipUrut(L2,32,"nafi");
    L2 = sisipUrut(L2,29,"furqon");
    L2 = sisipUrut(L2,12,"diani");

    cetak(L2,0);
    printf("\n");
    printf("\n");
    L3 = gabung(L1,L2);
    cetak(L3,1);
return 0;
}
