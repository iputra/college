#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    char merk[20],type[20],os[20];
    int harga;
    struct node *top;
};
typedef node node;

struct stack {
    node *top;
    node *capacity;
};
typedef stack stack;

node *buatNode()

stack push()
