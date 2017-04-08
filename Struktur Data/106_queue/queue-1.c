#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int id;
    char namaBuah[16];
    struct node *next;   
    };
typedef struct node node; 

struct queue{
    node *depan; //head
    node *belakang; //buntut
	int kapasitas; //berapa banyak benda yang bisa diisi
	int bbya; //banyak benda yang antri   
    };    
typedef struct queue queue; 

node *alokasiNode(int i,char nb[]){ //referensi tempatnya
    node *nBaru;
    nBaru=malloc(sizeof(node));
    nBaru->id=i;
    strcpy(nBaru->namaBuah,nb);
    nBaru->next=NULL;
    return nBaru;           
   }
   
queue inisialisasi(int N){ //memberikan nilai awal pada atribut
	queue Q;
	Q.belakang=Q.depan=NULL; //belum menunjuk apapun
	Q.kapasitas=N;
	Q.bbya=0; //sudah pasti nol isinya
	return Q;
}
   
//mengantrikan dibelakang sebelumnya sisip belakang   
queue enqueue(queue L, int ib, char nbb[]){  
    node *nBaruf;
    if(L.bbya<L.kapasitas){
	nBaruf=alokasiNode(ib,nbb);
	if(L.depan==NULL)
       L.depan=L.belakang=nBaruf;
    else{
        L.belakang->next=nBaruf;
        L.belakang=nBaruf; 
       } 
       L.bbya++;
	}
	else
		printf("Overflow!\n");
    return L;   
   }    
   
void cetakLL(queue L){
     node *pnlsr;
     pnlsr=L.depan;
     printf("|DEPAN<--");
     while(pnlsr!=NULL){
       printf("(%d,%s)<--",pnlsr->id,pnlsr->namaBuah);
       pnlsr=pnlsr->next;                                   
       }                    
     printf("BELAKANG\n");
     }   

queue dequeue(queue L,int *idd,char nbd[]){  //sebelumnya hapus depan
    //idd = id dequeue| nbd: nama buah dequeue
	node *target;
	*idd=-1; 
    strcpy(nbd,"N/A");
    if(L.bbya == 0){
		printf("\nUnderflow\n");
		return L;
		}
    else{
         target=L.depan;
         if(L.depan==L.belakang) 
                L.belakang=L.belakang->next; //bisa juga diNULL kan 
         L.depan=L.depan->next;
         *idd=target->id;
         strcpy(nbd,target->namaBuah);
         free(target);
         L.bbya--;
         return L; 
     	}                  
    }
    
int main(){
   queue ANTRIAN;
   ANTRIAN=inisialisasi(5);
   printf("Antrian buah yang nikmat :v\n\n");
   ANTRIAN=enqueue(ANTRIAN,1,"Melon");
   ANTRIAN=enqueue(ANTRIAN,2,"Pepaya");
   ANTRIAN=enqueue(ANTRIAN,3,"Semangka");
   ANTRIAN=enqueue(ANTRIAN,4,"Jeruk");
   ANTRIAN=enqueue(ANTRIAN,5,"Srikaya");
   ANTRIAN=enqueue(ANTRIAN,6,"Delima");
   cetakLL(ANTRIAN);
return 0;    
}   
