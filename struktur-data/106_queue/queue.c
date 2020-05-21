#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CAPACITY 100

struct queue {
    int data[MAX_CAPACITY];
    int size;
    int front;
};

typedef struct queue queue;

void init(queue *q) {
    q->size = 0;
    q->front = 0;
}

bool isEmpty(queue q) {
    return q.size == 0;
}

bool isFull(queue q) {
    return q.size == MAX_CAPACITY;
}

void enqueue(queue *q, int value) {
    if(isFull(*q)) {
        printf("Queue kosong...");
        exit(EXIT_FAILURE);
    }
    q->data[(q->size)++] = value;
}

int dequeue(queue *q) {
    if(isFull(*q)) {
        printf("Queue kosong...");
        exit(EXIT_FAILURE);
    }
    q->size--;
    return q->data[(q->front)++];
}
int first(queue q) {
    if(isEmpty(q)) {
        printf("stack kosong...");
        exit(EXIT_FAILURE);
    }
    return q.data[q.front];
}

int getSize(queue q) {
    return q.size;
}

void printqueue(queue q) {
    int i;
    printf("[");
    for(i=q.front;i<q.size + q.front;i++) {
        printf("%d", q.data[i]);
        if(i != (q.size + q.front)-1) printf(", ");
    }
    printf("]\n");
}

int main() {
    queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("sebelum isi queue diambil\n");
    printf("Isi queue \t\t");
    printqueue(q);
    printf("Nilai paling depan \t: %d\n",first(q));
    printf("Ukuran queue \t\t: %d\n",getSize(q));

    printf("\nMengambil isi queue...\n");
    printf("dequeue() pertama \t: %d\n",dequeue(&q));
    printf("dequeue() kedua \t: %d\n",dequeue(&q));

    printf("\nsetelah isi queue diambil\n");
    printf("Isi queue \t\t");
    printqueue(q);
    printf("Nilai paling depan \t: %d\n",first(q));
    printf("Ukuran queue \t\t: %d\n",getSize(q));
return 0;
}
