//���Լ������С������ 
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
		printf("���Լ����%d\n",m);
		printf("��С��������%d\n",a*b/m);
	}
	else if(n>m)
	{
		while(t!=0)
		{
			t=n%m;
			n=m;
			m=t;
		}
		printf("���Լ����%d\n",n);
		printf("��С��������%d\n",a*b/n);
	}
	else
	{
		printf("���Լ����%d\n",a);
		printf("��С��������%d\n",b);
	}
 } 
