linklist inis ()
{
    linklist L;
    L.head = NULL;
    L.tail = NULL;
    return L;
}

node * buatNode(int idb, char namab[])
{
    node *nb;
    nb = malloc (sizeof(node));
    nb->id = idb;
    strcpy(nb->nama, namab);
    nb->prev = NULL;
    nb->next = NULL;
    return nb;
}

linklist addDepan (linklist L, int idx, char namax[])
{
    node *nx;
    nx = buatNode (idx,namax);

    if(L.head == NULL)
    {
        L.head = L.tail = nx;
    }
    else
    {
        nx-> next = L.head;
        L.head->prev = nx;
        L.head = nx;
    }
    return L;
}

void cetak (linklist L, int mode)
{
    //mode 0: dari depan head-->tail
    //selainnya dari delakang (tail-->head)

    node *p;
    if(mode==0)
        {
            p = L.head; printf("{HEAD}<-->");
        }
        //p = L.head;
    else
        {
            p = L.tail; printf("{TAIL}<-->");
        }
        //p = L.tail;

    while (p != NULL)
    {
        printf("[%d, %s]<-->", p->id, p->nama);
        if (mode == 0)
            p = p->next;
        else
            p = p->prev;
    }
    if (mode == 0)
    printf("{TAIL}");
    printf("|");

}

linklist addBelakang (linklist L, int idx, char namax[])
{
    node *ny;
    ny = buatNode (idx, namax);

    if(L.head == NULL)
        L.head = L.tail = ny;
    else
    {
        ny->prev = L.tail;
        L.tail->next = ny;
        L.tail = ny;
    }
    return L;
}

linklist addNodeKeN (linklist L, int n, int idx, char namax[])
{
    node *ny, *pos;
    int j; //jumlah pergeseran yang telah terjadi
    ny = buatNode(idx, namax); //baris 73 gak perlu karena ada malloc, mubazir
    if(n==1)
        L = addDepan (L, idx, namax);

    else
    {
        j = 0;
        pos = L.head;
        while (pos != NULL && j<(n-2))
        {
            pos = pos->next;
            j++;
        }
        //printf("%d %d\n\n", j, pos->id);

        if (pos != NULL)
        {
            ny->prev = pos;
            ny->next = pos->next;


        if (pos->next != NULL)
            pos->next->prev = ny;
        else
            L.tail = ny;
        //pos->next->prev = ny; //aksi ini terlarang kalo nyisipnya dibelakang
        pos->next = ny;
    }
    else
    {
        printf("Nilai n = %d terlalu besar maks : %d)\n", n, j+1);
    }
    }
    return L;
}

linklist sisipUrut(linklist L, int id, char n[]) {
    node *nn,*pb1;

    if(L.head==NULL){
	    nn = buatNode(id,n);
	    L.head=L.tail=nn;
    }
    else {
	    if(id<=L.head->id) L = addDepan(L,id,n);
	    else if(id>L.tail->id) L = addBelakang(L,id,n);
        else{
	        nn = buatNode(id,n);
	        pb1 = L.head;
	        while(id>pb1->id)
		        pb1 = pb1->next;
	        nn->prev = pb1->prev;
	        nn->next = pb1;
	        pb1->prev->next = nn;
	        pb1->prev = nn;
	    }
    }

return L;
}

linklist delDepan (linklist L)
{
    node *t;
    if (L.head != NULL)
    {
        t=L.head;
        L.head = L.head->next;
        if(L.head == NULL)
            L.tail = NULL;
        else
            L.head->prev = NULL;
        free(t); //supaya lebih stabil, kalo data dikit gapapa, kalo banyak masalah
    }
    return L;
}

linklist delBelakang (linklist L)
{
    node *t;
    if(L.head != NULL)
    {
        t = L.tail;
        L.tail = L.tail->prev;
        if (L.tail == NULL)
            L.head = NULL;
        else
            L.tail->next = NULL;
            free(t);
    }
    return L;
}

linklist delNodeKeN(linklist L, int n)
{
    node *t;
    if (L.head != NULL)
    {
        if (n == L.head->id)
            L = delDepan(L);
        else if
            (n == L.tail->id)
            L = delBelakang(L);

        else
        {
            t = L.head;

            while (t != NULL && t->id != n)
            {
                t = t->next;

                if (t != NULL)
                {
                    t->prev->next = t->next;
                    t->next->prev = t->prev;
                    free(t);
                }
                else
                    printf("Node %d yang akan dihapus tidak ada", n);
            }
        }
    }
return L;
}

linklist gabung(linklist link1, linklist link2) {
    linklist linkTemp;
    node *pb;

    linkTemp = inis();
    pb = link1.head;
    do {
        linkTemp = sisipUrut(linkTemp,pb->id,pb->nama);
        pb = pb->next;
        if(pb->next == NULL)
            linkTemp = sisipUrut(linkTemp,pb->id,pb->nama);
    }while(pb->next != NULL);

    pb = link2.head;
    while(pb->next != NULL) {
        linkTemp = sisipUrut(linkTemp,pb->id,pb->nama);
        pb = pb->next;
        if(pb->next == NULL)
            linkTemp = sisipUrut(linkTemp,pb->id,pb->nama);
    }

return linkTemp;
}
