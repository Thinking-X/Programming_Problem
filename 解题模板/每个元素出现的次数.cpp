#include <stdio.h>//输出数组中每个元素出现的次数 
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
			printf("%d 出现 %d 次\n",a[i],b[i]);
		}
		
	}
 } 
