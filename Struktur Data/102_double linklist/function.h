llist inis() {
    llist L;
    L.head = L.tail = NULL;
return L;
}

node *buatNode(int i, char n[]) {
    node *pb;
    pb = malloc(sizeof(node));
    pb->id = i;
    strcpy(pb->nama,n);
    pb->next = NULL;
    pb->prev = NULL;
return pb;
}

llist addDepan(llist L, int i, char n[]) {
    node *nn;
    nn = buatNode(i,n);
    if(L.head == NULL)
        L.head = L.tail = nn;
    else {
        nn->next = L.head;
        L.head->prev = nn;
        L.head = nn;
    }
return L;
}

llist addBelakang(llist L, int i, char n[]) {
    node *nn;
    nn = buatNode(i,n);
    if(L.head == NULL)
        L.head = L.tail = nn;
    else {
        nn->prev = L.tail;
        L.tail->next = nn;
        L.tail = nn;
    }
return L;
}

llist sisipUrut(llist L, int i, char n[]) {
    node *nn,*pb;
    pb = L.head;
    if(L.head == NULL) {
        nn = buatNode(i,n);
        L.head = L.tail = nn;
    }
    else {
        if(i <= L.head->id)
            L = addDepan(L,i,n);
        else if(i > L.tail->id )
            L = addBelakang(L,i,n);
        else {
            nn = buatNode(i,n);
            while(pb->id<i)
                pb = pb->next;
            nn->next = pb;
            nn->prev = pb->prev;
            pb->prev->next = nn;
            pb->prev = nn;
        }
    }
return L;
} 

llist sisipNode(llist L, int pos, int i, char n[]) {
    node *nn,*pb;
    int counter;
    if(pos == 1)
        L = addDepan(L,i,n);
    else {
        nn = buatNode(i,n);
        counter = 0;
        pb = L.head;
        while(pos != '\0'&& counter < pos-2){
            pb = pb->next;
            counter++;
        }
        if(pos != '\0') {
            nn->prev = pb;
            nn->next = pb->next;
            if(pb->next != NULL) pb->next->prev = nn;
            else L.tail = nn;
            pb->next = nn;
        }
        else{
            printf("Nilai n:%d terlalu besar (maks: %d)\n",pos,counter+1);
        }
    }
return L;
}

llist delDepan(llist L) {
    node *pb;
    pb = L.head;
    if(L.head != NULL) {
        L.head = L.head->next;
        L.head->prev = NULL;
        free(pb);
    }
    else printf("tidak bisa di hapus");
return L;
}

llist delBelakang(llist L){
    node *pb;
    pb = L.tail;
    if(L.tail != NULL){
        L.tail = L.tail->prev;
        L.tail->next=NULL;
        free(pb);
    }
    else printf("tidak bisa dihapus");
return L;
}

void cetak(llist L, int mode) {
    node *pb;

    if(mode == 0)
        pb=L.head;
    else
        pb=L.tail;
    while(pb != NULL){
        printf("[%d, %s]<-->",pb->id,pb->nama);
        if(mode==0) pb = pb->next;
        else pb = pb->prev;
    }
}
