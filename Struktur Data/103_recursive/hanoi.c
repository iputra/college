#include <stdio.h>

void toh(int n, char awl[],char trans[],char tuj[]) {
    static int i;

    if(n==1)
        printf("%d. Pindahkan Ring 1 dari %s ke %s\n",++i,awl,tuj);
    else{
        toh(n-1,awl,tuj,trans);
        printf("%d Pindahkan Ring %d dari %s ke %s",++i,n,awl,tuj);
        toh(n-1,trans,awl,tuj);
    }
}

int main() {
    toh(10,"BS","Tugu Kujang","CB");
return 0;
}
