//ͷ�ļ�
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#include<ctype.h>
//#include<string.h>
//#include<time.h>
//int main()
//{
//	int n;
//	int arr[10]={0,1,2,3,4,5,6,7,8,9};
//	scanf("%d",&n);
//	printf("%d",search(arr,n,10)); 
//	return 0;
//}

//���Լ��
//int gcd(int a,int b)
//{
//	int c;
//	while(a%b)
//	{
//		c=a%b;
//		a=b;
//		b=c;
//	}
//	return b;
// }
//�˷���power 
// long long power(long long a,long long b)
// {
// 	long long tmp=1;
// 	for(long long i=0;i<b;i++)
// 	{
// 		tmp*=a;
// 	}
// 	return tmp;
// }
//������ ���ٳ� ���ٳ�
//https://blog.csdn.net/qq_19782019/article/details/85621386?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166519640216782428611056%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166519640216782428611056&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-85621386-null-null.142^v51^control,201^v3^add_ask&utm_term=%E5%BF%AB%E9%80%9F%E5%B9%82&spm=1018.2226.3001.4187 
//https://blog.csdn.net/Cyan_rose/article/details/83065026?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522166519672716782412577917%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=166519672716782412577917&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-83065026-null-null.142^v51^control,201^v3^add_ask&utm_term=%E9%BE%9F%E9%80%9F%E4%B9%98&spm=1018.2226.3001.4187
//#include<stdio.h>
//int main()
//{
//	long long a,b,p,ans=1;
//	scanf("%lld%lld%lld",&a,&b,&p);
//	while(b)
//	{
//		if(b&1)
//		{
//			ans=(ans*a-(long long)((long double)ans*a/p)*p+p)%p;
//		}
//		b>>=1;
//		a=(a*a-(long long)((long double)a*a/p)*p+p)%p;
//	}
//	printf("%lld",ans%p);
//	return 0;
//}



//������
//����ɸ 
//long long a[100000010]={0};
//int c[100000000];
//int main()
//{
//	int n;
//	long long k;
//	scanf("%d",&n);
//	for(long long i=2;i<n;i++)
//	{
//		if(!a[i])
//		{
//			for(long long j=i;j<=n;j+=i)
//			{
//				a[j]=1;
//			}
//			c[k]=i;
//			k++;
//		}
//	}
//	printf("%d\n",k);
//	for(int z=0;z<k;z++)
//	{
//		printf("%d,",c[z]);
//	}
//	return 0;
//}
//ŷ������
//int eular(int n) 
//{
//	int ans=n;
//	int i;
//	for(i=2;i*i<=n;i++)
//	{
//		if(n%i==0)
//		{
//			ans=ans/i*(i-1);
//			while(n%i==0)
//			    n/=i;
//		}
//	}
//	if(n>1)
//	ans=ans/n*(n-1);
//	return ans;
//} 


//qsort(arr,n,sizeof(arr[0]),cmp);
//int cmp(const void*p1,const void*p2)
//{
//	const int*a1=p1;
//	const int*a2=p2;
//	if(*a1<*a2)
//	return -1;
//	else if(*a1>*a2)
//	return 1;
//	else
//	return 0;
//}
//�������򣨴�0��sz-1�� 
//int partition(int a[],int left,int right)
//{
//	int i=left-1,j,tmp;
//	for(j=left;j<=right;j++)
//	{
//		if(a[j]<=a[right])
//		{
//			i++;
//			tmp=a[i];
//			a[i]=a[j];
//			a[j]=tmp;
//		}
//	}
//	return i;
//}
//void sort(int a[],int left,int right)
//{
//	int q;
//	if(left<right)
//	{
//		q=partition(a,left,right);
//		sort(a,left,q-1);
//		sort(a,q+1,right);
//	}
//}
//ð�����򣨴�sz�� 
//void bubble_sort(int arr[],int sz)
//{
//	int i=0;
//	for(i=0;i<sz-1;i++)
//	{
//		int j=0;
//		int flag=1;
//		for(j=0;j<sz-1-i;j++)
//		{
//			if(arr[j]>arr[j+1])
//			{
//				int tmp=arr[j];
//				arr[j]=arr[j+1];
//				arr[j+1]=tmp;
//				flag=0;
//			}		
//		}
//		if(flag==1)
//		{
//			break;
//		}	
//	}
//}

//�۰���ң�������Ԫ�ظ����� 
//int search(int arr[],int n,int sz)
//{
//	int left = 0;
//	int right =sz-1;
//	int mid = (left+right)/2;
//	while(left<=right) 
//	{
//		mid=(left+right)/2; 
//		if(arr[mid]<n)
//	{
//		left=mid+1;
//	}
//	else if(arr[mid]>n)
//	{
//		right = mid-1;
//	}
//	else
//	{
//		return mid; 
//	}
//	} 
//	return -1;	
//}
//�ҵ���һ�γ���λ�ã������±꣩
//int search(int tmp)
//{
//	int*p=bsearch(&tmp,arr,n,sizeof(int),cmp);
//	if(p==NULL)
//	return -1;
//	else
//	{
//		int tmp2=p-arr;
//		while(1)
//		{
//			p=bsearch(&tmp,arr,tmp2,sizeof(int),cmp);
//			if(p==NULL||tmp2==0)
//			break;
//			tmp2=p-arr;
//		}
//		return tmp2;
//	}
//} 



//��������� 
//#include<stdio.h>
//#include<string.h>
//char s1[1005],s2[1005];
//int int1[1005],int2[1005];
//int result[1000010];
//int main()
//{
//	int i,j;
//	int d;
//	int b;
//	int m;
//	int len;
//	scanf("%s %s",s1,s2);
//	int len1=strlen(s1);
//	int len2=strlen(s2);
//	for(i=0,j=len1-1;i<len1;i++,j--)
//	{
//		int1[j]=s1[i]-'0';
//	}
//	for(i=0,j=len2-1;i<len2;i++,j--)
//	{
//		int2[j]=s2[i]-'0';
//	}
//	
//	for(i=0;i<len2;i++)
//	{
//		d=0;
//		m=i;
//		for(j=0;j<len1;j++)
//		{
//			b=int2[i]*int1[j]+d+result[m];
//			result[m]=b%10;
//			m++;
//			d=b/10;
//		}
//		if(d>0)
//		result[m]=d;
//	}
//	len=len1+len2;
//	while(result[len]==0&&len>0)
//	{
//		len--;
//	}
//	for(i=len;i>=0;i--)
//	{
//		printf("%d",result[i]);
//	}
//	return 0;
//}




//��������� 
//srand(time(NULL));
//any=rand();


//ĳ��ĳ��ĳ�������ڼ� 
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#include<ctype.h>
//#include<string.h>
//#include<time.h>
//int getWeekDay(int year,int month,int day)
//{
//	int sum=0;
//	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
//	if(year>1582)
//	{
//		sum=(year-1583)*365;
//		sum+=(year-1581)/4;
//		sum-=(year-1501)/100;
//		sum+=(year-1201)/400;
//		if((year%4==0&&year%100!=0)||year%400==0)
//		a[1]=29;
//		for(int i=0;i<month-1;i++)
//		sum+=a[i];
//		sum+=day;
//	}
//	else
//	{
//		if(month==10)
//		sum=day-15;
//		else if(month==11)
//		sum+=day+16;
//		else
//		sum+=day+46;
//	}
//	sum+=5;
//	sum%=7;
//		return sum;
//}
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	switch(getWeekDay(n/10000,(n/100)%100,n%100))
//	{
//		case 0:
//			printf("Sun");
//			break;
//		case 1:
//			printf("Mon");
//			break;
//		case 2:
//			printf("Tue");
//			break;
//		case 3:
//			printf("Wed");
//			break;
//		case 4:
//			printf("Thu");
//			break;
//		case 5:
//			printf("Fri");
//			break;
//		case 6:
//			printf("Sat");
//			break;	
//	}
//	return 0;
//}

//ĳ����֮��������
//int days(int n1,int n2)
//{
//	int year1=n1/10000;
//	int month1=(n1/100)%100;
//	int day1=n1%100;
//	int year2=n2/10000;
//	int month2=(n2/100)%100;
//	int day2=n2%100;
//	if(year1==year2)
//	{
//		if(month1==month2)
//		return day2-day1;
//		else
//		return days2(year2,month2,day2)-days2(year1,month1,day1);
//	}
//	else
//	{
//		return years(year1,year2)+days2(year2,month2,day2)-days2(year1,month1,day1);
//	}
//}
//int days2(int yy,int mm,int dd)
//{
//	int sum=0,rn;
//	if((yy%4==0&&yy%100!=0)||yy%400==0)
//	rn=29;
//	else
//	rn=28;
//	switch(mm)//��1��1���ж����� 
//	{
//		case 1:
//			return dd-1;
//		case 2:
//		    return dd+30;
//		case 3:
//			return dd+30+rn;
//		case 4:
//			return dd+61+rn;
//		case 5:
//		    return dd+91+rn;
//		case 6:
//			return dd+122+rn;
//		case 7:
//			return dd+152+rn;
//		case 8:
//			return dd+183+rn;
//		case 9:
//			return dd+214+rn;
//		case 10:
//			return dd+244+rn;
//		case 11:
//			return dd+275+rn;
//		case 12:
//			return dd+305+rn;
//	}
//}
//int years(int yy1,int yy2)//yy1���1��1�յ�yy2��1��1�չ�������
//{
//	int sum=0;
//	for(int i=yy1;i<yy2;i++)
//	{
//		if((i%4==0&&i%100!=0)||i%400==0)
//		sum+=366;
//		else
//		sum+=365;
//	}
//	return sum;
//} 


//������
//���֧�ݹ� 
//#include<stdio.h>
//void game(int i,char a,char b,char c)
//{
//	if(i==1)
//	{
//		printf("move %d from %c to %c\n",i,a,c);
//	}
//	else
//	{
//		game(i-1,a,c,b);
//		printf("move %d from %c to %c\n",i,a,c);
//		game(i-1,b,a,c);
//	}
//}
//int main()
//{
//	int i;
//	char a='L';
//	char b='M';
//	char c='R';	
//	scanf("%d",&i);
//	scanf(" %c %c %c",&a,&b,&c);	
//	game(i,a,b,c);	
//	return 0;
//}


//���У�n 
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#include<ctype.h>
//#include<string.h>
//#include<time.h>
//int b[10]={1,1,1,1,1,1,1,1,1,1};
//int a[10]={0,0,0,0,0,0,0,0,0,0};//�ݹ�ÿ���Ǽ� 
//int n;
//void print(int m,int c)
//{
//	if(m==1)
//	{
//		for(int j=1;j<=n;j++)//�����һ��ʱ��ӡǰ���� 
//		if(a[j])
//		printf("%d ",a[j]);
//		for(int j=1;j<=n;j++)
//		if(b[j])
//		{
//			printf("%d\n",j);
//		}				
//		return;
//	}	
//	else
//	for(int i=1;i<=n;i++)
//	{
//		if(!b[i])continue;//����ѱ�ĳ��ѡ�е�Ԫ�� 
//		
//		b[i]=0;
//		a[c]=i;
//		print(m-1,c+1);
//		b[i]=1;
//		a[c]=0;
//	}
//}
//int main()
//{
//	scanf("%d",&n);
//	print(n,1);
//	return 0;
// }

//��ϣ�Cnm 
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#include<ctype.h>
//#include<string.h>
//#include<time.h>
//#define intmax 2147483647
//#define longlongmax 9223372036854775807
//int arr[12]={1,1,1,1,1,1,1,1,1,1,1,1};
//int brr[12]; 
//void print(int a,int b,int c)
//{
//	if(c>=b)
//	{
//		for(int i=0;i<b;i++)
//		printf("%d ",brr[i]);
//		printf("\r");
//		printf("\n");
//		return;
//	}
//	for(int i=1;i<=a;i++)
//	{
//		if(arr[i])
//		{
//			brr[c]=i;
//		}	
//		else
//		continue; 
//		arr[i]=0;
//		print(a,b,c+1);
//		arr[i]=1;
//		brr[c]=0;
//	}
//}
//int main()
//{
//	int m,n;
//	scanf("%d%d",&n,&m);
//	print(n,m,0); 
//	return 0;
//}

//Լɪ������ 
//int arr[110];
//int brr[110];
//int main()
//{
//	int n,s,m;
//	scanf("%d%d%d",&n,&s,&m);
//	arr[0]=1; 
//	for(int i=1;i<=n;i++)
//	arr[i]=i;
//	int j=s-1;
//	for(int i=1;i<=n;i++)
//	{
//		for(int k=0;k<m;k++)
//		{
//			if(!arr[j])
//			while(!arr[j])
//		    {
//			    j++;
//			    if(j>n)
//			    j=1;
//		    }
//		    else
//		    {
//		    	j++;
//		    	while(!arr[j])
//		        {
//			        j++;
//			        if(j>n)
//			        j=1;
//		        }
//			}		    
//		    if(j>n)
//			j=1;
//		}				
//		brr[i]=arr[j];
//		arr[j]=0;
//	}
//	for(int i=1;i<=n;i++)
//	printf("%d\n",brr[i]);
//	return 0;
//}