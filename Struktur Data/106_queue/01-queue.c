#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int id;
    char buah[20];
    struct node *next;
};
typedef struct node node;

struct queue{
    node *front;
    node *back;
    int capacity;
    int size;
};
typedef struct queue queue;

node *buatNode(int i, char n[]) {
    node *nn;
    nn = malloc(sizeof(node));
    nn->id = i;
    strcpy(nn->buah,n);
    nn->next = NULL;
return nn;
}

queue inis(int size) {
    queue q;

    q.front = NULL;
    q.back = NULL;
    q.capacity = size;
    q.size = 0;
return q;
}

queue enqueue(queue q, int i, char n[]) {
    node *nn;
    if(q.size < q.capacity) {
        nn = buatNode(i,n);
        if(q.front == NULL)
            q.front = q.back = nn;
        else{
            q.back->next = nn;
            q.back = nn;
        }
        q.size++;
    }
    else
        printf("Overflow!\n");
return q;
}   

queue dequeue(queue q) {
    node *pb;
    if(q.front == NULL)
        printf("Underflow!\n");
    else{
        pb = q.front;
        if(q.front == q.back)
            q.front = q.back = NULL;
        q.front = q.front->next;
        free(pb);
        q.size--;
    }
return q;
}

void cetak(queue q) {
    node *nn;
    nn = q.front;
    printf("| FRONT <-- ");
    while(nn != NULL) {
        printf("[%d] %s <-- ",nn->id, nn->buah);
        nn = nn->next;
    }
    printf(" BACK|");
}

int main() {
    queue ANTRIAN;

    ANTRIAN = inis(10);
    printf("antrian buah \n\n");
    ANTRIAN = enqueue(ANTRIAN, 12, "Pepaya");
    cetak(ANTRIAN);
    printf("\n");
    ANTRIAN = enqueue(ANTRIAN, 23, "Apel");
    cetak(ANTRIAN);
    printf("\n");
    ANTRIAN = enqueue(ANTRIAN, 32, "Nanas");
    cetak(ANTRIAN);
    printf("\n");
    printf("size = %d\n",ANTRIAN.size);
    printf("capacity = %d\n",ANTRIAN.capacity);
    cetak(ANTRIAN);
    printf("\n");
    ANTRIAN = dequeue(ANTRIAN);
    cetak(ANTRIAN);
    printf("\n");
    ANTRIAN = dequeue(ANTRIAN);
    cetak(ANTRIAN);
    printf("\n");
    printf("size = %d\n",ANTRIAN.size);
    printf("capacity = %d\n",ANTRIAN.capacity);
return 0;
}
