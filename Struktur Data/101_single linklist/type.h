struct node{
    int id;
    char nama[20];
    struct node *next;
};

typedef struct node node;

struct linklist{
    node *head;
    node *tail;
};

typedef linklist llist;

