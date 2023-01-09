//定义
typedef struct Node {
    int val;
    struct Node * next;
} *List;

//创建
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

//遍历
void printList(List L) {
    while (L != NULL) {
        printf("%d ", L->val);
        L = L->next;
    }
}

//插入
void insertList(List p, int item) {
    List q = (List) malloc(sizeof (struct Node));
    q->val = item;
    q->next = p->next;  // 让 q 指 p 的下一个结点
    p->next = q;        // 让 p->next 变成 q
}

//删除
int deleteList(List p) {
    if (p->next == NULL)
        return -1;
    List q = p->next;
    p->next = q->next;
    free(q);
    return 0;
}