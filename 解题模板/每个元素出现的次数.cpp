#include <stdio.h>//���������ÿ��Ԫ�س��ֵĴ��� 
int main()
{
	int a[10]={4,2,4,68,0,3,1,6,3,7};
	int b[10];
	int count=0;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(a[i]==a[j])
			{
				count++;
			}
		}
		b[i]=count;
		count=0;
	}
	for(int i=0;i<10;i++)
	{
		
		{
			printf("%d ���� %d ��\n",a[i],b[i]);
		}
		
	}
 } 
