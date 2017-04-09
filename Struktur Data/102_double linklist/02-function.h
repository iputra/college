llist inis() {
    llist L;

    L.head = NULL;
    L.tail = NULL;
return L;
}

node *buatNode(int i, char n[]) {
    node *nn;

    nn = malloc(sizeof(node));
    nn->id = i;
    strcpy(nn->nama,n);
    nn->next = NULL;
    nn->prev = NULL;
return nn;
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

    if(L.head == NULL){
        nn = buatNode(i,n);
        L.head = L.tail = nn;
    }
    else{
        if(L.head->id >= i)
            L = addDepan(L,i,n);
        else {
            pb = L.head;
            nn = buatNode(i,n);
            while(pb != NULL && L.head->id < i)
                pb = pb->next;
            if(pb == NULL) {
                nn->prev = L.tail;
                L.tail->next = nn;
                L.tail = nn;
            }
            else {
                nn->next = pb;
                nn->prev = pb->prev;
                pb->prev->next = nn;
                pb->prev = nn;
            }
        }
    }
return L;
}

llist sisipNode(llist L, int pos, int i, char n[]) {
    node *nn,*pb;
    int j = 0;

    if(pos == 1)
        L = addDepan(L,i,n);
    else {
        nn = buatNode(i,n);
        pb = L.head;
        while(pb != NULL && j <= pos-2)
            pb = pb->next;
        if(pb->next != NULL) {
            pb->next->prev = nn;
            nn->next = pb->next;
        }
        else {
            L.tail = nn;
        }
        nn->prev = pb;
        pb->next = nn;
    }
return L;
}

llist delDepan(llist L) {
    node *pb;

    if(L.head == NULL)
        printf("Linklist Kosong!,\n Tidak ada node yang bisa di hapus \n");
    else {
        pb = L.head;
        L.head = L.head->next;
        L.head->prev = NULL;
        free(pb);
    }
return L;
}

llist delBelakang(llist L) {
    node *pb;

    if(L.head == NULL)
        printf("Linklist Kosong!,\n Tidak ada node yang bisa di hapus \n");
    else {
        pb = L.tail;
        L.tail = L.tail->prev;
        L.tail->next = NULL;
        free(pb);
    }
return L;
}

llist delKe(llist L, int pos) {
    node *pb;
    int j=0;

    if(L.head == NULL)
        printf("Linklist Kosong!,\n Tidak ada node yang bisa di hapus \n");
    else if(pos == 1)
        L = delDepan(L);
    else {
        pb = L.head;
        while(pb != NULL && j < pos-1)
            pb = pb->next;
        if(pb == NULL) {
            printf("Tidak ada node di posisi %d",pos);
        }
        else {
            if(pb->next != NULL){
                pb->prev->next = pb->next;
                pb->next->prev = pb->prev;
            }
            else {
                L.tail = pb->prev;
                L.tail->next = NULL;
            }
            free(pb);
        }
    }
return L;
}

llist delID(llist L, int i) {
    node *pb;

    pb = L.head;
    if(L.head == NULL)
        printf("Linklist Kosong!,\n Tidak ada node yang bisa di hapus \n");
    else {
        while(pb != NULL && pb->id != i)
            pb = pb->next;
        if(pb->id == i) {
            if(L.head->id == i)
                L = delDepan(L);
            else if(L.tail->id == i)
                L = delBelakang(L);
            else {
                pb->prev->next = pb->next;
                pb->next->prev = pb->prev;
                free(pb);
            }
        }
    }
return L;
}

void cetak(llist L) {
    node *pb;

    printf("HEAD <--> ");
    pb = L.head;
    while(pb != NULL){
        printf("[%d] [%s] <--> ",pb->id,pb->nama);
        pb = pb->next;
    }
    printf("TAIL");
}
