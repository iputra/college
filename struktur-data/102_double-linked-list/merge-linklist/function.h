#include <stdlib.h>
#include "type.h"

llist inis() {
	llist L;
	L.head = NULL;
	L.tail = NULL;
return L;
}

node *buatNode(int i,char n[]) {
	node *pb;
	pb = malloc(sizeof(node));
	pb->id = i;
	strcpy(pb->nama,n);
	pb->next = NULL
return pb;
}

llist addBelakang(llist L, int i, char n[]) {
	node *nn;
	nn = buatNode(i,n);
	if(L.head == NULL)
			L.head = L.tail = nn;
	else {
		L.tail->next = nn;
		L.tail = nn;
	}
return L;
}

llist addDepan(llist L, int i, char n[]) {
	node *nn;
	nn = buatNode(i,n);
	if(L.head == NULL)
			L.head = L.tail = nn;
	else {
		nn->next = L.head;
		L.head = nn;
	}
return L;
}

void cetak(llist L) {
	node *nb;
	nb = L.head;
	while(nb!= NULL) {
		printf("[%d %s]-->",nb->id,nb->nama);
		nb = nb->next;
	}
	printf("|");
}

llist sisipUrut(llist L, int i, char n[]) {
	node *nn,*pb1,*pb2;
	nn = buatNode(i,n);

	if(L.head == NULL)
			L.head = L.tail = nn;
	else {
		if(i<=L.head->id) L = addDepan(L,i,n);
		else if(i>L.head) L = addBelakang(L,i,n);
		else {
			pb1 = pb2 = L.head;
			while(pb1->id<i) {
			pb2 = pb1;
			pb1 = pb1->next;
			}
		}
		nn->next = pb1;
		pb2->next = nn;
	}
return L;
}
