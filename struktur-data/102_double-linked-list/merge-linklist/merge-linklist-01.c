#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#include "type.h"

int main() {
	llist DATA;
	node *nb;

	DATA = inis();

	DATA = sisipUrut(DATA,132,"Sangga");
	DATA = sisipUrut(DATA,142,"Wisnu");
	DATA = sisipUrut(DATA,69,"Ikhsan");
	DATA = sisipUrut(DATA,100,"Nafi");
	
	cetak(DATA);

return 0;
}
