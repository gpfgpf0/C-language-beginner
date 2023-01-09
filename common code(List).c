//����
typedef struct Node {
    int val;
    struct Node * next;
} *List;

//����
List createList(int a[], int n) {
    List L = NULL, p = NULL, r = NULL;
 
    for(int i = 0; i < n; i++) {
        p = (List) malloc(sizeof (struct Node));
        p->val = a[i];
        p->next = NULL;
 
        if (L == NULL)
            L = p;
        else
            r->next = p;
        r = p;
    }
    return L;
}

//����
void printList(List L) {
    while (L != NULL) {
        printf("%d ", L->val);
        L = L->next;
    }
}

//����
void insertList(List p, int item) {
    List q = (List) malloc(sizeof (struct Node));
    q->val = item;
    q->next = p->next;  // �� q ָ p ����һ�����
    p->next = q;        // �� p->next ��� q
}

//ɾ��
int deleteList(List p) {
    if (p->next == NULL)
        return -1;
    List q = p->next;
    p->next = q->next;
    free(q);
    return 0;
}