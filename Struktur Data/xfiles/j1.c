#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    char merk[20],type[20],os[20];
    int harga;
    struct node *next;
};
typedef struct node node;

struct linkList {
    node *head;
    node *tail;
};
typedef struct linkList linkList;

node *buatNode(char merk[], char os[], char type[], int harga) {
    node *nn;

    nn = malloc(sizeof(node));
    strcpy(nn->merk,merk);
    strcpy(nn->os,os);
    strcpy(nn->type,type);
    nn->harga = harga;
    nn->next = NULL;

return nn;
}

linkList sisipDepan(linkList L, char merk[], char os[], char type[], int harga) {
    node *nn;

    nn = buatNode(merk,os,type,harga);
    if(L.head == NULL)
        L.head = L.tail = nn;
    else {
        nn->next = L.head;
        L.head = nn;
    }
return L;
}

linkList sisipBelakang(linkList L, char merk[], char os[], char type[], int harga) {
    node *nn;

    nn = buatNode(merk,os,type,harga);
    if(L.head == NULL)
        L.head = L.tail = nn;
    else {
        L.tail->next = nn;
        L.tail = nn;
    }
return L;
}

linkList mergeLL(linkList L1, linkList L2) {
    node *p1, *p2;
    linkList L3;
    L3.head = L3.tail = NULL;
    p1 = L1.head;
    p2 = L2.head;

    while(p1 != NULL || p2 != NULL) {
        if(p2 == NULL) {
            L3.tail->next = p1;
            L3.tail = p1;
            p1 = p1->next;
        }
        else if(p1->harga <= p2->harga){
            if(L3.head == NULL)
                L3.head = L3.tail = p1;
            else {
                L3.tail->next = p1;
                L3.tail = p1;
            }
            p1 = p1->next;
        }
        else {
            if(p1 == NULL) {
                L3.tail->next = p2;
                L3.tail = p2;
                p2 = p2->next;
            }
            else if(L3.head == NULL)
                L3.head = L3.tail = p2;
            else{
                L3.tail->next = p2;
                L3.tail = p2;
            }
            p2 = p2->next;
        }
    }
return L3;
}

void cetak(linkList L) {
    node *pb;
    int i=1;

    pb = L.head;
    while(pb != NULL) {
        printf("%d. %5d (%s,%s,%s)\n",i,pb->harga,pb->merk,pb->type,pb->os);
        pb = pb->next;
        i++;
    }
}

int main() {
    linkList DATAHP1,DATAHP2,DATAHP3;
    DATAHP1.head = DATAHP1.tail = NULL;
    DATAHP2.head = DATAHP2.tail = NULL;
    DATAHP3.head = DATAHP3.tail = NULL;

    DATAHP1 = sisipDepan(DATAHP1,"Samsung","Android","GTS5360",1700);
    DATAHP1 = sisipDepan(DATAHP1,"Apple","ios","Iphone5",1000);
    DATAHP1 = sisipDepan(DATAHP1,"Nokia","Symbian","N-gage",700);

    cetak(DATAHP1);
    printf("\n-----------------------------------------------\n");

    DATAHP2 = sisipBelakang(DATAHP2,"Cross","Windows phone","C1",1100);
    DATAHP2 = sisipDepan(DATAHP2,"Motorola","Linux","M10",900);
    cetak(DATAHP2);
    printf("\n-----------------------------------------------\n");

    DATAHP3 = mergeLL(DATAHP1,DATAHP2);
    cetak(DATAHP3);

return 0;
}
