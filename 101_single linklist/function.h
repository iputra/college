llist inis() {
    llist L;
    L.head = NULL;
    L.tail = NULL;
return L;
}

node *buatNode(int i, char n[]) {
    node *pb;
    pb = malloc(sizeof(node));
    pb->id = i;
    strcpy(pb->nama,n);

    pb->next = NULL;
return pb;
}

llist addBelakang(llist L, int i, char n[]) {
    node *nn;
    nn = buatNode(i,n);

    if(L.head == NULL)
        L.head = L.tail = nn;
    else {
        L.tail->next = nn;
        L.tail == nn;
    }
return L;
}

llist addDepan(llist L, int i, char n[]) {
    node *nn;
    nn = buatNode(i,n);

    if(L.head == NULL)
        L.head = L.tail = nn;
    else {
        nn->next = L.head;
        L.head = nn;
    }
return L;
}

void cetak(llist L) {
    node *nn;
    nn = L.head;

    while(nn != NULL) {
        printf("[%d] %s --> ",nn->id
                            ,nn->nama);
        nn = nn->next;
    }
    printf("|");
}

llist 
