#include<stdio.h>
#include<stdlib.h>

struct node {
    int id;
    struct node* next;
};

struct node* SortedMerge(struct node* a, struct node* b) {
    struct node* result = NULL;
    if (a == NULL) 
        return(b);
    else if (b==NULL) 
        return(a);
    if (a->id <= b->id) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else{
        result = b;
        result->next = SortedMerge(a, b->next);
    }
return(result);
}

void push(struct node** head_ref, int new_data){
    struct node* new_node = (struct node*) malloc(sizeof(struct node)); 
    new_node->id  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

void printList(struct node *node){

    printf("{ ");
    while (node!=NULL) {
        printf("%d ", node->id);
        node = node->next;
    }
    printf("}");
}
 
int main(){
    struct node* res = NULL;
    struct node* a = NULL;
    struct node* b = NULL;

    push(&a, 19);
    push(&a, 10);
    push(&a, 9);
    push(&a, 5);
    printf("Link list 1 = ");
    printList(a);
    printf("\n");

    push(&b, 21);
    push(&b, 20);
    push(&b, 7);
    push(&b, 1);
    printf("Link list 2 = ");
    printList(b);
    printf("\n");

    res = SortedMerge(a, b);

    printf("Merged Linked List is = ");
    printList(res);

    printf("the quick brown \n");
    return 0;
}
