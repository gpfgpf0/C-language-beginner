// 中缀转后缀https://www.luogu.com.cn/problem/P1175
// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// #include<ctype.h>
// #include<string.h>
// #include<time.h>
// typedef struct Node {
//     int jc;//判断存储的是数字还是符号
//     int val;
//     struct Node * right;
//     struct Node * left;
// } *List;
// int opc(char ch)
// {
//     switch (ch)
//     {
//     case '^':
//         return 3;
//     case '*':case '/':
//         return 2;
//     case '+':case '-':
//         return 1;
//     case '(':case ')':
//         return 0;
//     default:
//         return -1;
//     }
// }
// List create(List p,char c)
// {
//     if(p==NULL)
//     {
//         p=(List)malloc(sizeof(struct Node));
//         p->left=NULL;
//         p->right=NULL;
//         p->val=c;
//         return p;
//     }
//     else
//     {
//         List pp=(List)malloc(sizeof(struct Node));
//         pp->left=p;
//         pp->right=NULL;
//         p->right=pp;
//         pp->val=c;
//         return pp;
//     }
// }
// List de(List p)
// {
//     if(p==NULL)
//     return NULL;
//     else
//     {
//         List pp=p->left;
//         if(pp)
//         pp->right=p->right;
//         if(p->right)
//         (p->right)->left=pp;
//         free(p);
//         return pp;//返回删除结点的左边
//     }
// }
// void print(List p)
// {
//     while(p)
//     {
//         if(p->jc)
//         printf("%c ",p->val);
//         else
//         printf("%d ",p->val);
//         p=p->right;
//     }
//     printf("\n");
//     return ;
// }
// long long power(long long a,long long b)
// {
// 	long long tmp=1;
// 	for(long long i=0;i<b;i++)
// 	{
// 		tmp*=a;
// 	}
// 	return tmp;
// }
// int cal(char ch,int a,int b)
// {
//     switch (ch)
//     {
//     case '+':
//         return a+b;
//     case '-':
//         return a-b;
//     case '*':
//         return a*b;
//     case '/':
//         return a/b;
//     default:
//         return power(a,b);
//     }
// }
// int main()
// {
//     List data=NULL,op=NULL;//数字、符号
//     List data2=data,op2=op;
//     char ch;
//     while(scanf("%c",&ch)!=EOF)//中缀转后缀
//     {
//         if(isdigit(ch))
//         {
//             data2=create(data2,ch-'0');
//             if(data==NULL)
//             data=data2;
//             data2->jc=0;//代表数字
//         }        
//         else if(opc(ch)>=0)
//         {
//             while(op2&&ch!='('&&opc(op2->val)>=opc(ch)&&((op2->val!='^')||(ch!='^')))
//             {
//                 if(op2->val=='('&&ch==')')
//                 break;
//                 data2=create(data2,op2->val);
//                 data2->jc=1;//代表符号
//                 op2=de(op2);
//             }
//             if(op2&&op2->val=='('&&ch==')')
//             op2=de(op2);
//             else
//             {
//                 op2=create(op2,ch);
//                 if(op==NULL)
//                 op=op2;
//                 op2->jc=1; 
//             }          
//         }
//     }
//     while(op2)
//     {
//         data2=create(data2,op2->val);
//         data2->jc=1;
//         op2=de(op2);
//     }
//     print(data);
//     List tmp=data;
//     while (data->right)
//     {
//         while(tmp->right&&tmp->jc==0)
//         tmp=tmp->right;
//         char cc=tmp->val;
//         (tmp->left)->left->val=cal(cc,(tmp->left)->left->val,(tmp->left)->val);
//         de(tmp->left);
//         tmp=de(tmp);
//         print(data);
//     }
//     system("pause");
//     return 0;
// }

//验证栈序列https://www.luogu.com.cn/problem/P4387
// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// #include<ctype.h>
// #include<string.h>
// #include<time.h>
// typedef struct Node
// {
//     int val;
//     struct Node *up;
//     struct Node *down;
// }*List;
// int main()
// {    
//     int q,n;
//     scanf("%d",&q);
//     while(q--)
//     {
//         List d=(List)malloc(sizeof(struct Node));
//         List p=NULL,u=d;
//         d->val=-1;
//         d->down=NULL;
//         d->up=NULL;
//         int tmp,i;
//         scanf("%d",&n);
//         for(i=0;i<n;i++)
//         {
//             scanf("%d",&tmp);
//             if(u->val==-1)
//             u->val=tmp;
//             else
//             {
//                 p=(List)malloc(sizeof(struct Node));
//                 p->up=NULL;
//                 p->val=tmp;
//                 p->down=u;
//                 u->up=p;
//                 u=p;
//             }
//         }
//         p=d;
//         for(i=0;i<n;i++)
//         {
//             scanf("%d",&tmp);
//             while(p&&tmp!=p->val)
//             p=p->up;
//             if(!p)
//             {
//                 i++;
//                 break;
//             }            
//             if(p->down==NULL)
//             {
//                 d=p->up;
//                 if(p->up)
//                 (p->up)->down=NULL;
//                 free(p);
//                 p=d;
//             }
//             else
//             {
//                 List pp=p->down;
//                 pp->up=p->up;
//                 if(p->down)
//                 {
//                     pp->down=(p->down)->down;
//                     if(pp->down)
//                     (pp->down)->up=pp;
//                 }
//                 if(p->up)
//                 (p->up)->down=pp;
//                 free(p);
//                 p=pp;
//             }
//         }
//         if(i<n)
//         {
//             for(;i<n;i++)
//             scanf("%d",&tmp);
//             while(d)
//             {
//                 p=d->up;
//                 free(d);
//                 d=p;
//             }
//             printf("No\n");
//         }
//         else
//         printf("Yes\n");
//     }
//     return 0;
// }

//二叉搜索树的建立与遍历https://www.luogu.com.cn/problem/T224291
// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// #include<ctype.h>
// #include<string.h>
// #include<time.h>
// typedef struct Node {
//     int val;
//     int num;
//     struct Node * left;
//     struct Node * right;
// } *Tree;
// Tree create(Tree p,int x)
// {
//     p=(Tree)malloc(sizeof(struct Node));
//     p->left=NULL;
//     p->right=NULL;
//     p->val=x;
//     p->num=1;
//     return p;
// }
// void print1(Tree p)
// {
//     if(p==NULL)
//     return ;
//     for(int i=0;i<p->num;i++)
//     printf("%d ",p->val);
//     print1(p->left);
//     print1(p->right);
//     return ;
// }
// void print2(Tree p)
// {
//     if(p==NULL)
//     return ;
//     print2(p->left);
//     for(int i=0;i<p->num;i++)
//     printf("%d ",p->val);        
//     print2(p->right);
//     return ;
// }
// void print3(Tree p)
// {
//     if(p==NULL)
//     return ;
//     print3(p->left);
//     print3(p->right);
//     for(int i=0;i<p->num;i++)
//     printf("%d ",p->val);
//     return ;
// }
// int main()
// {
//     int n,x;
//     char s[10];
//     Tree L=NULL;
//     scanf("%d",&n);
//     while(n--)
//     {
//         scanf("%s",s);
//         Tree p=L,pp=L;
//         if(strcmp(s,"ins")==0)
//         {
//             scanf("%d",&x);            
//             while(p)
//             {
//                 if(x<p->val)
//                 {
//                     if(p->left==NULL)
//                     {
//                         p->left=create(p->left,x);
//                         break;
//                     }                    
//                     else
//                     p=p->left;
//                 }
//                 else if(x>p->val)
//                 {
//                     if(p->right==NULL)
//                     {
//                         p->right=create(p->right,x);
//                         break;
//                     }                    
//                     else
//                     p=p->right;
//                 }
//                 else
//                 {
//                     p->num++;
//                     break;
//                 }
//             }
//             if(L==NULL)
//             L=create(L,x);
//         }
//         else if(strcmp(s,"cnt")==0)
//         {
//             scanf("%d",&x);
//             while(p)
//             {
//                 if(x<p->val)
//                 p=p->left;
//                 else if(x>p->val)
//                 p=p->right;
//                 else
//                 {
//                     printf("%d\n",p->num);
//                     break;
//                 }                
//             }
//             if(p==NULL)
//             printf("0\n");
//         }
//         else if(strcmp(s,"height")==0)
//         {
//             scanf("%d",&x);
//             int height=1;
//             while(p)
//             {
//                 if(x<p->val)
//                 p=p->left;
//                 else if(x>p->val)
//                 p=p->right;
//                 else
//                 break;
//                 height++;
//             }
//             if(p==NULL)
//             printf("0\n");
//             else
//             printf("%d\n",height);
//         }
//         else if(strcmp(s,"vlr")==0)
//         {
//             print1(L);
//             printf("\n");
//         }
//         else if(strcmp(s,"lvr")==0)
//         {
//             print2(L);
//             printf("\n");
//         }
//         else
//         {
//             print3(L);
//             printf("\n");
//         }
//     }
//     return 0;
// }

//中序遍历、后序遍历推出前序遍历https://www.luogu.com.cn/problem/P1030
// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// #include<ctype.h>
// #include<string.h>
// #include<time.h>
// char str[30];
// char str2[30];
// typedef struct Node {
//     int val;
//     struct Node * left;
//     struct Node * right;
// } *Tree;
// Tree create(Tree p,int x)
// {
//     p=(Tree)malloc(sizeof(struct Node));
//     p->left=NULL;
//     p->right=NULL;
//     p->val=x;
//     return p;
// }
// void print(Tree p)
// {
//     if(p==NULL)
//     return ;
//     printf("%c",str[p->val]);
//     print(p->left);
//     print(p->right);
//     return ;
// }
// int main()
// {
//     scanf("%s",str);//中序遍历
//     scanf("%s",str2);//后序遍历
//     Tree L=NULL;
//     for(int i=strlen(str2)-1;i>=0;i--)
//     {
//         int x=0;
//         Tree p=L;
//         for(int j=0;j<strlen(str);j++)
//         if(str[j]==str2[i])
//         {
//             x=j;
//             break;
//         }
//         while(p)
//         {
//             if(x<p->val)
//             {
//                 if(p->left==NULL)
//                 {
//                     p->left=create(p->left,x);
//                         break;
//                     }                    
//                     else
//                     p=p->left;
//                 }
//             else if(x>p->val)
//             {
//                 if(p->right==NULL)
//                 {
//                     p->right=create(p->right,x);
//                     break;
//                 }                    
//                 else
//                 p=p->right;
//             }
//         }
//         if(L==NULL)
//         L=create(L,x);
//     }
//     print(L);
//     return 0;
// }

//最长不升子序列&最长上升子序列https://www.luogu.com.cn/problem/P1020
// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// #include<ctype.h>
// #include<string.h>
// #include<time.h>
// #define intmax 2147483647
// #define longlongmax 9223372036854775807
// #define randmax 32767
// #define pi 3.1415926535897932
// int arr[100010];
// int up[100010];
// int low[100010];
// int len=1,len2=1;
// int search(int tmp)
// {
//     int left=1,right=len,mid; 
//     while(left<right)
//     {
//         mid=(left+right)/2;
//         if(up[mid]>=tmp)
//         left=mid;
//         else
//         right=mid;
//         if(left+1==right)
//         break;
//     }
//     return right;
// }
// int search2(int tmp)
// {
//     int left=1,right=len2,mid; 
//     while(left<right)
//     {
//         mid=(left+right)/2;
//         if(low[mid]>=tmp)
//         right=mid;
//         else
//         left=mid;
//         if(left+1==right)
//         break;
//     }
//     return right;
// }
// int main()
// {
//     int n=0;
//     while(scanf("%d",&arr[n])!=EOF)
//     n++;
//
//     up[1]=arr[0];
//     for(int i=1;i<n;i++)
//     {
//         if(arr[i]<=up[len])
//         {
//             len++;
//             up[len]=arr[i];
//         }
//         else if(arr[i]>=up[1])
//         {
//             up[1]=arr[i];
//         }
//         else
//         {
//             up[search(arr[i])]=arr[i];//从右向左数最后一个arr[i]比up[]大的
//         }
//     }
//
//     low[1]=arr[0];
//     for(int i=1;i<n;i++)
//     {
//         if(arr[i]>low[len2])
//         low[++len2]=arr[i];
//         else if(arr[i]<=low[1])
//         low[1]=arr[i];
//         else
//         {
//             low[search2(arr[i])]=arr[i];//从左向右数第一个arr[i]比low[]大的
//         }        
//     }
//     printf("%d\n%d",len,len2);
//     return 0;
// }

//四维dp->三维https://www.luogu.com.cn/problem/P1006
// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// #include<ctype.h>
// #include<string.h>
// #include<time.h>
// #define intmax 2147483647
// #define longlongmax 9223372036854775807
// #define randmax 32767
// #define pi 3.1415926535897932
// #define max(a,b) (a>b?a:b)
// #define min(c,d) (c>d?d:c)
// int arr[60][60];
// int dp[120][60][60];
// int main()
// {
//     int m,n;
//     scanf("%d%d",&m,&n);
//     for(int i=1;i<=m;i++)
//     for(int j=1;j<=n;j++)
//     scanf("%d",&arr[i][j]);
//     for(int k=3;k<m+n+1;k++)
//     {
//         for(int i=1;i<=m;i++)
//         {
//             if(k-i<0)
//             break;
//             for(int j=1;j<=m;j++)
//             {
//                 if(k-j<0)
//                 break;
//                 dp[k][i][j]=max(max(dp[k-1][i][j],dp[k-1][i-1][j-1]),max(dp[k-1][i-1][j],dp[k-1][i][j-1]))+arr[i][k-i]+arr[j][k-j];
//                 if(i==j)
//                 dp[k][i][j]-=arr[i][k-i];
//             }            
//         }
//     }
//     printf("%d",dp[m+n][m][m]);
//     return 0;
// }

//BFS+队列，蓝桥杯算法训练-跳马
// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// #include<ctype.h>
// #include<string.h>
// #include<time.h>
// #define intmax 2147483647
// #define longlongmax 9223372036854775807
// #define randmax 32767
// #define pi 3.1415926535897932
// int arr[10][10];//方格
// int a,b,c,d,min=0;
// typedef struct Node {
//     int x,y;
//     struct Node * next;
// } *List;
// int seek(List pL)
// {   
//     List pp=pL,L=pL;
//     while(pp->next)
//     pp=pp->next;//标记当前层中链表的头（L）、尾（pp）
//     pL=pp;//pL永远指向链表尾
//     while(1)
//     {
//         int m=L->x,n=L->y;
//     for(int i=m-2;i<=m+2;i++)
//     {
//         if(i==m)
//         continue;
//         for(int j=n-2;j<=n+2;j++)
//         {
//             if(j==n)
//             continue;
//             if((i-m)*(i-m)+(j-n)*(j-n)==5&&i>=1&&i<=8&&j>=1&&j<=8)
//             {
//                 if(arr[i][j]==-1)
//                 {
//                     printf("%d",min+1);
//                     exit(0);
//                 }
//                 else if(arr[i][j]==0)
//                 {
//                     List p=(List)malloc(sizeof(struct Node));                    
//                     pL->next=p;
//                     p->x=i;
//                     p->y=j;
//                     p->next=NULL;
//                     arr[i][j]=1;
//                     pL=p;
//                 }
//             }
//         }
//     }
//     if(L==pp)
//     break;
//     else
//     {
//         List ttmp=L;
//         L=L->next;
//         free(ttmp);
//     }    
//     }
//     if(pp->next)
//     {
//         min++;
//         List tt=pp->next;
//         free(pp);
//         seek(tt);//进入下一层
//     }
//     return 0;
// }
// int main()
// {    
//     scanf("%d%d%d%d",&a,&b,&c,&d);
//     arr[a][b]=1;
//     arr[c][d]=-1;
//     List L=(List)malloc(sizeof(struct Node));
//     L->next=NULL;
//     L->x=a;
//     L->y=b;
//     seek(L);
//     return 0;
// }

//DFS+回溯，蓝桥杯算法训练-娜神平衡（分组过程中两组和的差不超过r）
// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// #include<ctype.h>
// #include<string.h>
// #include<time.h>
// #define intmax 2147483647
// #define longlongmax 9223372036854775807
// #define randmax 32767
// #define pi 3.1415926535897932
// #define max(a,b) (a>b?a:b)
// #define min(c,d) (c>d?d:c)
// int a[100];
// int b[100];
// int arr[100];
// int n,r,sp;
// int cmp(const void*p1,const void*p2)
// {
// 	const int*a1=(int *)p1;
// 	const int*a2=(int *)p2;
// 	if(*a1<*a2)
// 	return -1;
// 	else if(*a1>*a2)
// 	return 1;
// 	else
// 	return 0;
// }
// void part(int numa,int numb,int num,int suma,int sumb)
// {
//     if(num==n)
//     {
//         qsort(a,numa,sizeof(a[0]),cmp);
//         qsort(b,numb,sizeof(b[0]),cmp);
//         if(bsearch(&sp,a,numa,sizeof(a[0]),cmp))
//         {
//             for(int i=0;i<numa;i++)
//             printf("%d ",a[i]);
//             printf("\n");
//             for(int i=0;i<numb;i++)
//             printf("%d ",b[i]);
//         }
//         else
//         {
//             for(int i=0;i<numb;i++)
//             printf("%d ",b[i]);
//             printf("\n");
//             for(int i=0;i<numa;i++)
//             printf("%d ",a[i]);
//         }
//         exit(0);
//     }    
//     for(int i=0;i<n;i++)
//     {
//         if(arr[i]==0)
//         continue;
//         if(abs(suma+arr[i]-sumb)<=r)
//         {
//             a[numa]=arr[i];
//             arr[i]=0;
//             part(numa+1,numb,num+1,suma+a[numa],sumb);
//             arr[i]=a[numa];
//             a[numa]=0;
//         }
//         if(abs(sumb+arr[i]-suma)<=r)
//         {
//             b[numb]=arr[i];
//             arr[i]=0;
//             part(numa,numb+1,num+1,suma,sumb+b[numb]);
//             arr[i]=b[numb];
//             b[numb]=0;
//         }
//     }
//     return;
// }
// int main()
// {    
//     scanf("%d%d",&n,&r);
//     for(int i=0;i<n;i++)
//     scanf("%d",&arr[i]);
//     sp=arr[0];
//     part(0,0,0,0,0);
//     return 0;
// }

//组合+排列，蓝桥杯算法训练-粘木棍
//#include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// #include<ctype.h>
// #include<string.h>
// #include<time.h>
// #define intmax 2147483647
// #define longlongmax 9223372036854775807
// #define randmax 32767
// #define pi 3.1415926535897932
// #define max(a,b) (a>b?a:b)
// #define min(c,d) (c>d?d:c)
// int arr[12]={1,1,1,1,1,1,1,1,1,1,1,1};
// int brr[12];
// int crr[10];
// int drr[10];
// int cha=intmax;
// int n,mm;
// int b[10]={1,1,1,1,1,1,1,1,1,1};
// int a[10]={0,0,0,0,0,0,0,0,0,0};//递归每层是几 
// void print(int a,int b,int c);
// void printt(int m,int c)
// {
// 	if(m==1)
// 	{
//         int k=0;
// 		for(int j=1;j<=n;j++)//到最后一层时打印前几层 
// 		if(a[j])
// 		drr[k++]=crr[a[j]-1];
// 		for(int j=1;j<=n;j++)
// 		if(b[j])
// 		{
// 			drr[k++]=crr[j-1];
// 		}
//         print(n-1,mm-1,0);				
// 		return;
// 	}	
// 	else
// 	for(int i=1;i<=n;i++)
// 	{
// 		if(!b[i])continue;//标记已被某层选中的元素 		
// 		b[i]=0;
// 		a[c]=i;
// 		printt(m-1,c+1);
// 		b[i]=1;
// 		a[c]=0;
// 	}
// }
// void print(int a,int b,int c)
// {
// 	if(c>=b)
// 	{
//         int mmax=0,mmin=intmax;
//         int ttmp=0;
// 		for(int i=0;i<b;i++)
//         {
//             int tmp=0;
//             for(int j=ttmp;j<brr[i];j++)
//             tmp+=drr[j];
//             ttmp=brr[i];
//             if(tmp>mmax)
//             mmax=tmp;
//             if(tmp<mmin)
//             mmin=tmp;
//         }
//         ttmp=0;
//         for(int i=brr[b-1];i<n;i++)
//         ttmp+=drr[i];
//         if(ttmp>mmax)
//         mmax=ttmp;
//         if(ttmp<mmin)
//         mmin=ttmp;
//         if(mmax-mmin<cha)
//         cha=mmax-mmin;
// 		return;
// 	}
// 	for(int i=1;i<=a;i++)
// 	{
// 		if(arr[i])
// 		{
// 			brr[c]=i;
// 		}	
// 		else
// 		continue; 
// 		arr[i]=0;
// 		print(a,b,c+1);
// 		arr[i]=1;
// 		brr[c]=0;
// 	}
// }
// int main()
// {
//     scanf("%d%d",&n,&mm);
//     if(n==mm)
//     {
//         int nmax=0,nmin=intmax;
//         int tmp;
//         for(int i=0;i<n;i++)
//         {
//             scanf("%d",&tmp);
//             if(tmp>nmax)
//             nmax=tmp;
//             if(tmp<nmin)
//             nmin=tmp;
//         }
//         printf("%d",nmax-nmin);
//     }
//     else if(mm==1)
//     printf("0");
//     else
//     {
//         for(int i=0;i<n;i++)
//         scanf("%d",&crr[i]);
//         printt(n,1);
//         printf("%d",cha);
//     }
//     return 0;
// }

// DFS,单词接龙https://www.luogu.com.cn/problem/P1019
// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// #include<ctype.h>
// #include<string.h>
// #include<time.h>
// #define intmax 2147483647
// #define longlongmax 9223372036854775807
// #define randmax 32767
// #define pi 3.1415926535897932
// #define max(a,b) (a>b?a:b)
// #define min(c,d) (c>d?d:c)
// int n;
// char word[22][20];
// int num[22][2];//单词长度，使用次数
// int arr[22][22];//第i个单词连接第j个单词的最小连接部分，不能连为0
// int find(int tmp)
// {
//     int mm=0,tt;
//     int flag=1;
//     for(int i=0;i<n;i++)
//     {
//         if(arr[tmp][i]&&num[i][1]<2)
//         {
//             flag=0;
//             num[i][1]++;
//             tt=find(i)+num[tmp][0]-arr[tmp][i];
//             num[i][1]--;
//             if(tt>mm)
//             mm=tt;
//         }
//     }
//     if(flag)
//     return num[tmp][0];
//     return mm;
// }
// int main()
// {    
//     char ch;
//     scanf("%d",&n);
//     for(int i=0;i<n;i++)
//     {
//         scanf("%s",&word[i]);
//         num[i][0]=strlen(word[i]);
//     }    
//     scanf(" %c",&ch);
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             for(int k=1;k<=num[i][0];k++)
//             {
//                 if(strstr(word[j],word[i]+num[i][0]-k)==word[j])
//                 {
//                     arr[i][j]=k;
//                     break;
//                 } 
//             }            
//         }
//     }
//     int nmax=0,ttmp;
//     for(int i=0;i<n;i++)
//     {
//         if(word[i][0]==ch)
//         {
//             num[i][1]++;
//             ttmp=find(i);
//             num[i][1]--;
//             if(ttmp>nmax)
//             nmax=ttmp;
//         }
//     }
//     printf("%d",nmax);
//     return 0;
// }

// 很妙的模拟，导弹拦截2https://www.luogu.com.cn/problem/P1158
// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// #include<ctype.h>
// #include<string.h>
// #include<time.h>
// #define intmax 2147483647
// #define longlongmax 9223372036854775807
// #define randmax 32767
// #define pi 3.1415926535897932
// #define max(a,b) (a>b?a:b)
// #define min(c,d) (c>d?d:c)
// int arr[100010][2];
// int aa[100010][2];
// int cmp(const void*p1,const void*p2)
// {
// 	const int*a1=(int *)p1+1;
// 	const int*a2=(int *)p2+1;
// 	if(*a1<*a2)
// 	return -1;
// 	else if(*a1>*a2)
// 	return 1;
// 	else
// 	return 0;
// }
// int main()
// {
//     int x1,y1,x2,y2,n;
//     int a=0,b=0,sum=0;
//     scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&n);
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d%d",&arr[i][0],&arr[i][1]);
//         aa[i][0]=i;
//         aa[i][1]=(x1-arr[i][0])*(x1-arr[i][0])+(y1-arr[i][1])*(y1-arr[i][1]);
//     }
//     qsort(aa,n,sizeof(aa[0]),cmp);
//     sum=a=aa[n-1][1];
//     int tmp=0;
//     for(int i=n-1;i>=0;i--)
//     {
//         tmp=(arr[aa[i][0]][0]-x2)*(arr[aa[i][0]][0]-x2)+(arr[aa[i][0]][1]-y2)*(arr[aa[i][0]][1]-y2);
//         if(tmp>b)
//         b=tmp;
//         if(i)
//         a=aa[i-1][1];
//         else 
//         a=0;
//         if(sum>a+b)
//         sum=a+b;
//     }
//     printf("%d",sum);
//     return 0;
// }

//树形dp，蓝桥杯算法训练-强力党逗志凡https://blog.csdn.net/weixin_45728231/article/details/123479706?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522167798620616800197043076%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=167798620616800197043076&biz_id=&utm_medium=distribute.pc_search_result.none-task-code-2~all~first_rank_ecpm_v1~pc_rank_34-4-123479706-0-null-null.142
// #include<stdio.h>
// #include<stdlib.h>
// #include<math.h>
// #include<ctype.h>
// #include<string.h>
// #include<time.h>
// #define intmax 2147483647
// #define longlongmax 9223372036854775807
// #define randmax 32767
// #define pi 3.1415926535897932
// #define max(a,b) (a>b?a:b)
// #define min(c,d) (c>d?d:c)
// int arr[210][2];
// int brr[210][210];
// int ans[210][210];
// int n,m;
// void Dfs(int k)
// {
// 	for(int i=0;i<arr[k][1];i++)
// 	{
// 		Dfs(brr[k][i]);
// 		for(int j=m-1;j>=0;j--)
// 		{
// 			for(int l=0;l<=j;l++)
// 			{
// 				ans[k][j]=max(ans[k][j],ans[k][j-l]+ans[brr[k][i]][l]);
// 			}
// 		}
// 	}
// 	for(int i=m;i>=0;i--)
// 	{
// 		if(i==0)
// 		ans[k][0]=0;
// 		else
// 		ans[k][i]=ans[k][i-1]+arr[k][0];
// 	}
// }
// int main()
// {	
// 	int a,b;
// 	scanf("%d%d",&n,&m);
// 	m++;
// 	for(int i=1;i<=n;i++)
// 	scanf("%d",&arr[i][0]);
// 	arr[0][1]=1;
// 	brr[0][0]=1;
// 	for(int i=1;i<=n-1;i++)
// 	{
// 		scanf("%d%d",&a,&b);
// 		brr[a][arr[a][1]++]=b;
// 	}
// 	Dfs(0);
// 	printf("%d",ans[0][m]);
// 	return 0;
// }



//To be continued……