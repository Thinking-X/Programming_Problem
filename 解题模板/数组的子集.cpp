//求a数组的子集,除去空集  
#include<stdio.h>
#define N 6
int main()
{
	int a[N]={1,2,3,4,5,6};
	int b[N];
	int i=1,j=0,t,count=1,max=1;
	for(int k=0;k<N;k++)
	{
		max*=2;
	}
	max=max-1;
	while(i<=max)
	{	
		t=i;
		while(j<N)
		{
			b[j]=t%2;
			t=t/2;
			j++;
		}
		i++;
		j=0;
		for(int k=N-1;k>=0;k--)
		{
			if(b[k]==1)
			printf("%d ",a[k]);
		}
		printf("-----%d\n",count++);
	}
	return 0;
}
