#include<stdio.h>
#define intmax 2147483647
#define longlongmax 9223372036854775807
#define randmax 32767
#define pi 3.1415926535897932
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


//单调队列
// typedef struct Node {
//     int val;
// 	int num;
//     struct Node * left,*right;
// } *List;
// List create(int v,int n)
// {
//     List q=(List)malloc(sizeof(struct Node));
//     q->left=q->right=NULL;
//     q->val=v;
//     q->num=n;
//     return q;
// }
// List del(List s)//优先返回左边
// {
//     if(s==NULL)
//     return NULL;
//     List q;
//     if(s->left&&s->right)
//     {
//         s->left->right=s->right;
//         s->right->left=s->left;
//         q=s->left;
//         free(s);
//         return q;
//     }
//     else if(s->left)
//     {
//         s->left->right=NULL;
//         q=s->left;
//         free(s);
//         return q;
//     }
//     else if(s->right)
//     {
//         s->right->left=NULL;
//         q=s->right;
//         free(s);
//         return q;
//     }
// 	else
// 	{
// 		free(s);
// 		return NULL;
// 	}
// }
// List insert(List s,List t,int v,int n)//先左后右
// {
//     if(s==t&&s==NULL)
//     return NULL;
//     List q=(List)malloc(sizeof(struct Node));
//     q->val=v;
//     q->num=n;
//     if(s==NULL)
//     {
//         t->left=q;
//         q->right=t;
//         q->left=NULL;
//     }
//     else if(t==NULL)
//     {
//         s->right=q;
//         q->left=s;
//         q->right=NULL;
//     }
//     else
//     {
//         s->right=q;
//         t->left=q;
//         q->left=s;
//         q->right=t;
//     }
//     return q;
// }




//二叉树定义
typedef struct Node {
    int val;
    struct Node * left;
    struct Node * rihgt;
} *Tree;


//二叉树插入
void insert(Tree L,int item)
{
    if(L==NULL)
    {
        L=(Tree)malloc(sizeof(struct Node));
        L->left=NULL;
        L->rihgt=NULL;
        L->val=item;
        //return L;
    }
    else
    {
        Tree p=L;
        while(p)
        {
            L=p;
            if(item<L->val)
            p=L->left;
            else
            p=L->rihgt;
        }
        //插入
    }
}


//中序遍历
void print(Tree p)
{
    if(p==NULL)
    return ;    
    print(p->left);
    printf("%d",p->val);
    print(p->rihgt);
    return ;
}


//平衡二叉树的插入
void insert(Tree L,int item)
{
    if(L==NULL)
    {
        L=(Tree)malloc(sizeof(struct Node));
        L->left=NULL;
        L->rihgt=NULL;
        L->val=item;
        //return L;
    }
    else
    {
        Tree p=L;
        while(p)
        {
            L=p;
            if(item<L->val)
            p=L->left;
            else if(item>L->val)
            p=L->rihgt;
            else
            {
                //do something
                break;
            }
        }
        
    }
}



//最小堆的定义
typedef struct Node{
    int arr[100];
    int num;
    int max;
}*Heap;

//哈夫曼树的定义
typedef struct Node2{
    int weight;
    struct Node2* left;
    struct Node2* right;
}*Tree2;

//创建（完全二叉树）
Heap create(int n)
{
    Heap H=(Heap)malloc(sizeof(struct Node));
    // H->arr=(int*)malloc((n+1)*sizeof(int*));
    H->num=0;
    H->max=n;
    H->arr[0]=-intmax-1;
    return H;
}

//插入
void insert(Heap H,int tmp)
{
    if(H->num==H->max)
    return;
    int i=++H->num;
    for(;H->arr[i/2]>tmp;i/=2)
    H->arr[i]=H->arr[i/2];
    H->arr[i]=tmp;
}

//删除根节点
int delete1(Heap H)
{
    if(H->num==0)
    return -1;
    int i=1,j=2,min=H->arr[1];
    for(;i*2<=H->num;i=j)
    {
        j=2*i;
        if((j<H->num)&&(H->arr[j]>H->arr[j+1]))
        j++;
        if(H->arr[H->num]<H->arr[j])
        break;
        else
        H->arr[i]=H->arr[j];
    }
    H->arr[i]=H->arr[H->num];
    H->num--;
    return min;
}


// //创建哈夫曼树
// Tree2 hfm(Heap H)
// {
//     Tree2 T;
//     for(int i=1;i<H->num;i++)
//     {
//         T=(Tree2)malloc(sizeof(struct Node2));
//         T->left=delete1(H);
//         T->right=delete1(H);
//         T->weight=T->left->weight+T->right->weight;
//         insert(H,T);
//     }
//     T=delete1(H);
//     return T;
// }

//弗洛伊德算法
//http://t.csdn.cn/A6cqx
    // for(int k=1;k<=n;k++)//中间点
    // for(int i=1;i<=n;i++)
    // for(int j=1;j<=n;j++)    
    // if(arr[j][j]>arr[i][k]+arr[k][j]&&arr[i][k]>1e-6&&arr[k][j]>1e-6)
    // arr[i][j]=arr[j][i]=arr[i][k]+arr[k][j];

    // for(int k=0;k<10;k++)//中间点
    // for(int i=0;i<10;i++)
    // for(int j=0;j<10;j++)    
    // if(arr[i][j]>arr[i][k]+arr[k][j])//记得标记不能走的
    // arr[i][j]=arr[i][k]+arr[k][j];


// 树状数组
// #define lowbit(i) (i&(-i))
// int arr[1000010];
// int n;
// void add(int x,int k)
// {
//     for(int i=x;i<=n;i+=lowbit(i))
//     arr[i]+=k;
// }
// int ask(int x)//[1,x]区间的和
// {
//     int sum=0;
//     for(int i=x;i;i-=lowbit(i))
//     sum+=arr[i];
//     return sum;
// }