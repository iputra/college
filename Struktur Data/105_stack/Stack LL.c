#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int id;
    char namaBuah[16];
    struct node *next;   
    };
typedef struct node node; 

struct stack{
    int kapasitas;
    int bbsi; //banyak benda saat ini
    node *top;   
    };    
typedef struct stack stack; 

node *alokasiNode(int i,char nb[]){
    node *nBaru;
    nBaru=malloc(sizeof(node));
    nBaru->id=i;
    strcpy(nBaru->namaBuah,nb);
    nBaru->next=NULL;
    return nBaru;           
   }
   
stack inisialisasi(int n){
   stack S;
   S.top=NULL;
   S.kapasitas=n;
   S.bbsi=0;
   return S;
   }

stack push(stack L, int ib, char nbb[]){
    node *nBaruf;
    if(L.bbsi<L.kapasitas){
                           
            nBaruf=alokasiNode(ib,nbb);
            if(L.top==NULL)
               L.top=nBaruf;
            else{
                nBaruf->next =L.top;
                L.top=nBaruf;  
               }       
    L.bbsi++;
    }
    else
      printf("Overflow bang\n");
    return L;   
   }  
   
   
void cetakLL(stack L){
     node *pnlsr;
     int i;
     pnlsr=L.top;
     printf("\nKONDISI STACK SAAT INI\n\n");
     for(i=1;i<=L.kapasitas-L.bbsi;i++)
        printf(" |                |\n");
     while(pnlsr!=NULL){
       printf(" |(%3d,%10s)|",pnlsr->id,pnlsr->namaBuah);
       if(pnlsr==L.top) printf("<---TOP");
        printf("\n");                        
       pnlsr=pnlsr->next;                                   
       }
       printf("  ----------------\n");                    
     }   

stack pop(stack L,int *idp,char nbp[]){
    node *target;
    *idp=-1;
    strcpy(nbp,"N/A");
    if(L.bbsi == 0){printf("Underflow\n"); return L;}
    else{
         target=L.top; 
         L.top=L.top->next;
         *idp=target->id;
         strcpy(nbp,target->namaBuah);
         free(target);
         L.bbsi--;
         return L; 
     }                  
    }

int main(){
   stack P1;
   int idHasil;
   char buahHasil[16];
   P1=inisialisasi(5);
   P1=push(P1,100,"Jeruk");
   P1=push(P1,200,"Pepaya");
   P1=push(P1,300,"Melon");
   P1=push(P1,400,"Durian");
   cetakLL(P1);
   P1=pop(P1,&idHasil,buahHasil);printf("\nHasil Pop: %d,%s\n",idHasil,buahHasil);
   cetakLL(P1);
   P1=pop(P1,&idHasil,buahHasil);printf("\nHasil Pop: %d,%s\n",idHasil,buahHasil);
   P1=pop(P1,&idHasil,buahHasil);printf("\nHasil Pop: %d,%s\n",idHasil,buahHasil);
   P1=pop(P1,&idHasil,buahHasil);printf("\nHasil Pop: %d,%s\n",idHasil,buahHasil);
   P1=pop(P1,&idHasil,buahHasil);printf("\nHasil Pop: %d,%s\n",idHasil,buahHasil);
   cetakLL(P1);
return 0;    
}   
