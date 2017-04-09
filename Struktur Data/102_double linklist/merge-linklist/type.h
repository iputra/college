struct node{
	int id;
	char nama[11];

	struct node *next;
};
typedef struct node node;

struct linkedList{
	node *head;
	node *tail;
};
typedef struct linkedlist llist;


