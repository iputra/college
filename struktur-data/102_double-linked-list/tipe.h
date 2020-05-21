struct node
{
    int id;
    char nama [16];
    struct node *prev;
    struct node *next;

};
typedef struct node node;

struct linklist
{
    node *head;
    node *tail;
};
typedef struct linklist linklist;
