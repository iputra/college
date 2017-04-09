#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    char merk[11],type[15],os[10];
    int harga;
    struct node *next;
};
typedef struct node node;

struct stack {
    node *top;
    int capacity,pos;
};
typedef struct stack stack;

stack inisialisasi(int n) {
    stack S;
    S.top = NULL;
    S.capacity = n;
    S.pos = 0;
return S;
}

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

stack push(stack S, char merk[], char os[], char type[], int harga) {
    node *nn;

    if(S.pos <= S.capacity-1){
        nn = buatNode(merk,os,type,harga);
        if(S.top == NULL)
            S.top = nn;
        else {
            nn->next = S.top;
            S.top = nn;
        }
    S.pos++;
    }
    else {
        printf("Overflow! data (%s,%s) gagal di-push\n",type,os);
    }
return S;
}

stack pop(stack S, char merk[], char os[], char type[], int *harga) {
    node *pb;
    *harga = -1;
    strcpy(merk,"N/A");
    strcpy(type,"N/A");
    strcpy(os,"N/A");
    if(S.pos == 0)
        printf("Underflow!\n");
    else {
        pb = S.top;
        S.top = S.top->next;
        strcpy(merk,pb->merk);
        strcpy(type,pb->type);
        strcpy(os,pb->os);
        *harga = pb->harga;
        free(pb);
        S.pos--;
    }
return S;
}

void cetakStack(stack S) {
    node *nn;
    int i,j=S.capacity;

    nn = S.top;
    printf("KONDISI STACK SAAT INI\n");
    for(i=1;i<=S.capacity-S.pos;i++) {
        printf("[%d]|\t\t\t\t\t\t|\n",j);
        j--;
    }
    while(nn != NULL){
        printf("[%d]| %5d ( %8s,%11s,%11s ) |\n",j,nn->harga,nn->merk,nn->type,nn->os);
        nn = nn->next;
        j--;
    }
    printf("    --------------------------------------------\n");
}

int main(){
    stack DataHP;
    DataHP = inisialisasi(4);
    char merkPop[11];
    char soPop[15];
    char tipePop[10];
    int hargaPop;

    DataHP=push(DataHP,"Samsung","Android","Galaxy Note",1700);
    DataHP=push(DataHP,"Apple","Ios","Iphone 6",2000);
    DataHP=push(DataHP,"Nokia","Symbian","Lumia",700);
    DataHP=push(DataHP,"Asus","Android","Zenfone",1000);
    DataHP=push(DataHP,"Cross","Windows phone","C1",300);
    cetakStack(DataHP);
    DataHP=pop(DataHP,merkPop,soPop,tipePop,&hargaPop);
    DataHP=pop(DataHP,merkPop,soPop,tipePop,&hargaPop);
    cetakStack(DataHP);
    getchar();
    return 0;
}
