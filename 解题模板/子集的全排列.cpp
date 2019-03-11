//在N个数中选择m个数(m<=N),进行全排列，输出所有情况
//如下，num表示N个数的数组，a是m个数的数组，表示每种情况
//state数组记录num中某个位置的选中情况 
#include<stdio.h>
#define N 7
#define m 5 
int num[N]={1,2,3,4,5,6,7};
int state[N]={0};
int a[m];
int count=0;
void func(int index)
{
	if(index==m)
	{
		count++;
		for(int i=0;i<m;i++)
		{
			printf("%d  ",a[i]);
		}
		printf("-----%d\n",count);
		return;
	}
	for(int i=0;i<N;i++)
	{
		if(!state[i])
		{
			state[i]=1;
			a[index]=num[i];
			func(index+1);
			state[i]=0;
		}
	}
}
int main()
{
	func(0);
	printf("%d",count);
	return 0;
}
