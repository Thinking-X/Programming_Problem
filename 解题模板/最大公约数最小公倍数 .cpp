//最大公约数，最小公倍数 
#include<stdio.h>
int main()
{
	int a,b,m,n,t=1;
	scanf("%d%d",&a,&b);
	m=a;n=b;
	if(m>n)
	{
		while(t!=0)
		{
			t=m%n;
			m=n;
			n=t;
		}
		printf("最大公约数：%d\n",m);
		printf("最小公倍数：%d\n",a*b/m);
	}
	else if(n>m)
	{
		while(t!=0)
		{
			t=n%m;
			n=m;
			m=t;
		}
		printf("最大公约数：%d\n",n);
		printf("最小公倍数：%d\n",a*b/n);
	}
	else
	{
		printf("最大公约数：%d\n",a);
		printf("最小公倍数：%d\n",b);
	}
 } 
